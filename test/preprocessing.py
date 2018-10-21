import numpy as np
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.feature_selection import mutual_info_classif
from sklearn.cross_decomposition import PLSRegression
from scipy.linalg import eigh
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


class Preprocessor:
    def __init__(self, scaler_type, n_components):
        if scaler_type == "standard":
            # Standardize features by removing the mean and scaling
            # to unit variance
            self.scaler = StandardScaler()
        elif scaler_type == "minmax":
            # Transforms features by scaling each feature to a given range
            # of (0,1) which is default argument
            self.scaler = MinMaxScaler()
        self.pca = PCA(n_components)
        self.pls = PLSRegression(n_components=n_components, scale=False)

    def standardize(self, train, test):
        train_std = self.scaler.fit_transform(train)
        test_std = self.scaler.transform(test)
        return (train_std, test_std)

    def project_on_pca(self, train, test):
        train_pca = self.pca.fit_transform(train)
        test_pca = self.pca.transform(test)
        return (train_pca, test_pca)

    def project_on_pls(self, train, test, y_train, y_test):
        train_pls, _ = self.pls.fit_transform(train, y_train)
        test_pls, _ = self.pls.transform(test, y_test)
        return (train_pls, test_pls)

    def mutual_info_select(self, F, y, threshold):
        # Estimate mutual information for a discrete target variable.
        mi = list(enumerate(mutual_info_classif(F, y)))
        f_best = []
        for (ind, rank) in mi:
            if rank > threshold:
                f_best.append(ind)
        return f_best

# Mutual information (MI) between two random variables is a non-negative value,
# which measures the dependency between the variables. It is equal to zero if
# and only if two random variables are independent,
# and higher values mean higher dependency.
