import numpy as np
import pdb; pdb.set_trace()
import sys
sys.path.append('../')
import feature_selection.featureselection as feature
import pandas
import matplotlib
import os
import csv
from sklearn.preprocessing import label_binarize
from pls_DA_package import pls_DA_function
from pls_DA_package import final_test_DA
from pls_DA_package import feature_selection_DA
from pls_DA_package import set_plot_dir
from pls_DA_package import set_MI_true, set_MI_false
matplotlib.use('Agg')
import matplotlib.pyplot as plt


# add path to the dataset

path_to_features1 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/nsynth_features/"

path_to_features2 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_more_cat/'

path_to_features3 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/mel/"

path_to_features4 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_less_cat/'

path_to_features5 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/opensmile/"

std = False
MI = False

# location to extract plots
plot = "temp/"

# name of the tool features are extracted with
features = ['nsynth', 'pyaudio_more_cat',
            'mel_frequency_energy', 'pyaudio_less_cat', 'opensmile_IS_09']

path_list = [path_to_features1, path_to_features2, path_to_features3,
             path_to_features4, path_to_features5]

# path to labels 
path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels/'

component_list = [16, 17, 18, 15, 15]

np.random.seed(200)

for l in xrange(1):
    path_to_features = path_list[l]
    print features[l]
    if features[l] == 'pyaudio_less_cat':
        emotions = ['ang', 'exc', 'neu', 'sad']
    else:
        emotions = ['ang', 'exc', 'neu', 'sad', 'fru', 'hap', 'sur',
                    'fea', 'xxx']
    data = feature.Load_features(path_to_features, path_to_labels, features[l], emotions)
    x, y = data.data()
    if std is True:
        plot = plot + 'std/'
    if MI is True:
        plot = plot + '_MI_'

    plsda = feature.PLSDA(x, y, features[l], plot)
    plsda.PLS_process(plot)
    selection = feature.feature_selection(x, y, features[l], plot)
    selection.mutual_information()
    selection.plot_features()

    test = feature.final_test()
    test.plot(x, y, features[l], plot, component_list[l])
