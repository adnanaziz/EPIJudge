from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier
from sklearn.model_selection import train_test_split
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import sys
sys.path.append('../')
import feature_selection.featureselection as feature
import feature_selection.grid_search_svm as svm


path_to_features = "/home/ga25gux/tensorflow_python2/EPIJudge/example_dataset/"

path_to_labels = "/home/ga25gux/tensorflow_python2/EPIJudge/example_labels_regression/"

features = 'nsynth'

path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels/'

plot = 'plot/'
std = False
MI = False

name = 'grid_search'
print 'std:' + str(std) + ' MI' + str(MI)

component_list = [10, 13, 16]

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
