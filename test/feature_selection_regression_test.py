import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import sys
sys.path.append('../')
import feature_selection.featureselection as feature

path_to_features1 = "/home/ga25gux/tensorflow_python2/EPIJudge/example_dataset/"

std = False
MI = False

plot = "plot/"

features = 'nsynth'

path_list = path_to_features1

path_to_labels = "/home/ga25gux/tensorflow_python2/EPIJudge/example_labels_regression/"

component_list = 16

np.random.seed(200)


path_to_features = path_list
print features
if features == 'pyaudio_less_cat':
    emotions = ['ang', 'exc', 'neu', 'sad']
else:
    emotions = ['ang', 'exc', 'neu', 'sad', 'fru', 'hap', 'sur',
                'fea', 'xxx']
data = feature.Load_features(path_to_features, path_to_labels, features,
                             emotions, reg=True)
x, y = data.data()
if std is True:
    plot = plot + 'std/'
if MI is True:
    plot = plot + '_MI_'

plsda = feature.PLSDA(x, y, features, plot, reg=True)
plsda.PLS_process(plot)
selection = feature.feature_selection(x, y, features, plot, reg=True)
selection.mutual_information()
selection.plot_features()

test = feature.final_test()
test.plot(x, y, features, plot, component_list, reg=True)
