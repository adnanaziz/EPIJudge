import numpy as np
import pandas
from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn import decomposition
import matplotlib
import os
import csv
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

class SVM_parameter_search:
    def __init__(self, x, y, save, feature, name, kernel, component_list):
        self.feature = feature
        self.kernel = [kernel]
        power_C = range(-5, -4)
        power_gamma = range(-3, -2)
        self.C_values = [np.float_power(2, power) for power in power_C]
        self.gamma_values = [np.float_power(2, power) for power in power_gamma]
        self.component_list = component_list
        self.save = save

    def grid_search(self, classifier):
        parameters = {
            "clf__estimator__C": self.C_values,
            "clf__estimator__kernel": self.kernel,
            "clf__estimator__gamma": self.gamma_values,
        }
        print str(classifer)
        model = classifier(SVC(cache_size=3000))
        pipe = Pipeline([
            ('scale', StandardScaler()),
            ('clf', model),
        ])
        clf = GridSearchCV(pipe, param_grid=parameters, cv=3, scoring='accuracy', n_jobs=-1, verbose=1, return_train_score=False)
        clf.fit(x, y)
        plot_grid(clf, self.save, 'none',
                      str(classifer), self.feature, self.kernel[0])

    def grid_search_pca(self, classifer):
        pca = decomposition.PCA()
        parameters = {
            "clf__estimator__C": self.C_values,
            "clf__estimator__kernel": self.kernel,
            "clf__estimator__gamma": self.gamma_values,
            'dim_red__n_components': self.component_list,
            'dim_red': [pca]
        }
        print str(classifer)
        model = classifier(SVC(cache_size=3000))
        pipe = Pipeline([
            ('scale', StandardScaler()),
            ('dim_red', pca),
            ('clf', model),
        ])
        clf = GridSearchCV(pipe, param_grid=parameters, cv=3, scoring='accuracy', n_jobs=-1, verbose=1, return_train_score=False)
        clf.fit(x, y)
        plot_grid(clf, self.save, 'pca',
                      str(classifer), self.feature, self.kernel[0])


        def plot_grid(self, clf, save, method_str, classifier_str, feature, kernel):
            data_frame = pandas.DataFrame(clf.cv_results_)
            data_frame['param_clf__estimator__C'] = data_frame['param_clf__estimator__C'].astype(np.float64).apply(np.log2)
            data_frame['param_clf__estimator__gamma'] = data_frame['param_clf__estimator__gamma'].astype(np.float64).apply(np.log2)

            if method_str == 'none':
                pvt = pandas.pivot_table(data_frame, values='mean_test_score', index=['param_clf__estimator__C'], columns='param_clf__estimator__gamma')
            else:
                pvt = pandas.pivot_table(data_frame, values='mean_test_score', index=['param_clf__estimator__C', 'param_dim_red__n_components'], columns='param_clf__estimator__gamma')
                plt.figure()
                ax = sns.heatmap(pvt, annot=False, linewidths=.1)
                plt.xlabel('Gamma power of 2')
                plt.ylabel('C power of 2' + method_str + 'component number')
                if method_str == 'none':
                    plt.ylabel('C power of 2 with no reduction_method')
                plt.savefig(save + classifier_str + feature +
                            '_' + name + '_' + method_str + '_' + kernel)
                plt.close()
                with open(save + classifier_str +
                          feature + '_' + name + '_' +
                          method_str + '_' +
                          'best_parameters' +
                          '_' + kernel
                          + '.csv', 'w') as csvfile:
                    w = csv.writer(csvfile, delimiter=',')
                    w.writerow(['Best parameters'])
                    w.writerow(['clf.best_params', clf.best_params_])
                    w.writerow(['best_score', clf.best_score_])
