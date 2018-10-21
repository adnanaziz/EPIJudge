import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import sys
sys.path.append('../')
import feature_selection.featureselection as feature

# add path to the dataset

path_to_features1 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/nsynth_features/"

std = False
MI = False

# location to extract plots
plot = "plot/"

# name of the tool features are extracted with
features = 'nsynth'

path_list = path_to_features1

# path to labels
path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels/'

component_list = 16

np.random.seed(200)


path_to_features = path_list
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
