import numpy as np
import os
import sys
sys.path.append('../')
import emotion_in_speech.featureselection as feature

# add path to the dataset

path = os.path.abspath(__file__)

path = os.path.abspath(os.path.join(path, os.pardir))

parentDir = os.path.abspath(os.path.join(path, os.pardir))

path_to_labels = os.path.abspath(os.path.join(parentDir,
                                              "example_labels_classification"))
path_to_labels = path_to_labels + '/'
path_to_features = os.path.abspath(os.path.join(parentDir, "example_dataset/"))
path_to_features = path_to_features + '/'

std = False
MI = False

# location to extract plots
plot = "plot/"

# name of the tool features are extracted with
features = 'nsynth'

component_list = 16

np.random.seed(200)

print features
emotions = ['ang', 'exc', 'neu', 'sad', 'fru', 'hap', 'sur',
            'fea', 'xxx']
data = feature.Load_features(path_to_features, path_to_labels,
                             features, emotions)
x, y = data.data()
if std is True:
    plot = plot + 'std/'
if MI is True:
    plot = plot + '_MI_'

plsda = feature.PLSDA(x, y, features, plot)
plsda.PLS_process(plot)
selection = feature.feature_selection(x, y, features, plot)
selection.mutual_information()
selection.plot_features()

test = feature.final_test()
test.plot(x, y, features, plot, component_list)
