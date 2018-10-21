import numpy as np
import pandas
from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn import decomposition
import feature_selection.featureselection as feature
import matplotlib
import os
import csv
import SVM_parameter_search as svm
from sklearn.svm import SVC
from sklearn.model_selection import GridSearchCV
from preprocessing import Preprocessor
import seaborn as sns
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import label_binarize
from svm_package import create_cross_val_set
from svm_package import create_val_set_for_grid_search
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import pdb; pdb.set_trace()

# emotions = ['ang', 'exc', 'neu', 'sad', 'fru', 'hap', 'sur', 'fea', dis, 'xxx']
# emotions number
# ang=1106, exc = 1041, neu = 1708, sad = 1084
# fru = 595, hap = 595, sur = 107, fea=40 ,dis=2
# xxx=2507, oth=3


path_to_features1 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/nsynth_features/"

path_to_features2 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_more_cat/'

path_to_features3 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/mel/"

path_to_features4 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_less_cat/'

path_to_features5 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/opensmile/"

save_file = '/home/ga25gux/tensorflow_python2/workspace/results/models/svm/IEMOCAP/'

save = ['', save_file]
features = ['nsynth', 'pyaudio_more_cat',
            'mel_frequency_energy', 'opensmile_IS_09']

std = True
MI = False

print 'std:' + str(std) + ' MI' + str(MI) 

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

    classifier = [OneVsRestClassifier, OneVsOneClassifier]
    svm_search = svm.SVM_parameter_search(x, y, save, feature, name, kernel, component_list)
    for i in xrange(2):
        svm_search.grid_search(classifer[i])
        svm_search_pca.grid_search(classifer[i])
