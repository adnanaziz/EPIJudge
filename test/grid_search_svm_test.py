from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier
from sklearn.model_selection import train_test_split
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import pdb; pdb.set_trace()
import sys
sys.path.append('../')
import feature_selection.featureselection as feature
import feature_selection.grid_search_svm as svm

# emotions = ['ang', 'exc', 'neu', 'sad', 'fru',
# 'hap', 'sur', 'fea', dis, 'xxx']
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


features = ['nsynth', 'pyaudio_more_cat',
            'mel_frequency_energy', 'opensmile_IS_09']

path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels/'

path_list = [path_to_features1, path_to_features2, path_to_features3,
             path_to_features5]

plot = 'plot/'
std = False
MI = False

name = 'grid_search'
print 'std:' + str(std) + ' MI' + str(MI)

component_list = [10, 13, 16]
for l in xrange(1):
    path_to_features = path_list[l]
    print features[l]
    if features[l] == 'pyaudio_less_cat':
        emotions = ['ang', 'exc', 'neu', 'sad']
    else:
        emotions = ['ang', 'exc', 'neu', 'sad', 'fru', 'hap', 'sur',
                    'fea', 'xxx']
    data = feature.Load_features(path_to_features, path_to_labels,
                                 features[l], emotions)
    x, y = data.data()
    if std is True:
        plot = plot + 'std/'
    if MI is True:
        plot = plot + '_MI_'

    classifier = [OneVsRestClassifier, OneVsOneClassifier]
    classifier_str = ['OneVsRestClassifier', 'OneVsOneClassifier']
    kernel = ['rbf', 'sigmoid']

    x_train, x_test, y_train, y_test = train_test_split(
        x, y, test_size=1/4, random_state=200)
    power_C = range(-5, -4)
    power_gamma = range(-3, -2)

    for k in xrange(len(kernel)):
        svm_search = svm.SVM_parameter_search(x, y, plot,
                                              features[k], name, kernel[k],
                                              component_list, power_C,
                                              power_gamma)
        for i in xrange(2):
            svm_search.grid_search(classifier[i], classifier_str[i])
            svm_search.grid_search_pca(classifier[i], classifier_str[i])
