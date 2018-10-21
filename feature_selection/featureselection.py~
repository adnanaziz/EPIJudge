import numpy as np
import pandas
import matplotlib
import os
import csv
from sklearn.preprocessing import label_binarize
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.feature_selection import f_classif, mutual_info_classif
from sklearn.cross_decomposition import PLSRegression
from sklearn.feature_selection import f_regression, mutual_info_regression
from preprocessing import Preprocessor
import sys
matplotlib.use('Agg')
import matplotlib.pyplot as plt
sys.path
sys.path.append('/home/ga25gux/tensorflow_python2/workspace/tools/sammon/')
from sammon import sammon


class Load_features:
    def __init__(self, path_to_features, path_to_labels, name, emotions,
                 MI=False, std=False, reg=False):
        self.reg = reg
        self.path_to_features = path_to_features
        self.path_to_labels = path_to_labels
        self.name = name
        self.emotions = emotions
        self.MI = MI
        self.std = std

    def load_x(self, name):
        df = pandas.read_csv(name, sep=',', index_col=None)
        row_shape = df.shape[0]
        x = np.mean(df, axis=0)
        if self.std is True:
            x_std = np.std(df, axis=0)
            x = np.hstack((x, x_std))
        return np.array(x, dtype=float), row_shape

    def load_x_opensmile(self, name):
        df = pandas.read_csv(name, sep=';', index_col=None)
        df = df.iloc[:, 3:]
        row_shape = df.shape[0]
        x = np.mean(df, axis=0)
        if self.std is True:
            x_std = np.std(df, axis=0)
            x = np.hstack((x, x_std))
        return np.array(x, dtype=float), row_shape
    
    def load_y(self, name):
        df = pandas.read_csv(name, sep=',', index_col=None)
        y = np.array(df.values)
        return y

    def get_features(self, path_x, path_y):
        files = os.listdir(path_x)
        tx = []
        ty = []
        row_shapes = []
        a = len(files)
        k = 1
        for f in files:
            if k % 500 == 0:
                print str(k) + " out of " + str(a)
                # for testing purposes
                return tx, ty, row_shapes
            k += 1
            if self.name != "opensmile_IS_09":
                x, row_shape = self.load_x(path_x + '/' + f)
            else:
                self.load_x_opensmile(path_x + '/' + f)
            y = self.load_y(path_y + f)
            if len(x) > 0:
                tx.append(np.array(x, dtype=float))
                ty.append(y[0])
                row_shapes.append(row_shape)
        tx = np.array(tx)
        ty = np.array(ty)
        return tx, ty, row_shapes

    def get_features_regression(self, path_x, path_y):
        max_row_shape = 0
        files = os.listdir(path_x)
        tx = []
        ty = np.empty([1, 2], dtype=float)
        a = len(files)
        k = 1
        for f in files:
            if k % 1000 == 0:
                print str(k) + " out of " + str(a)
                return tx, ty[1:, :], max_row_shape
            k += 1
            x, row_shape = self.load_x(path_x + '/' + f)
            if max_row_shape < row_shape:
                max_row_shape = row_shape
            y = self.load_y(path_y + f)
            if len(x) > 0:
                tx.append(np.array(x, dtype=float))
                ty = np.vstack((ty, y[0]))
        tx = np.array(tx)
        ty = np.array(ty)
        return tx, ty[1:, :], max_row_shape

    def to_categorical(self, y, available_emotions):
        return label_binarize(y, np.asarray(available_emotions))

    def check_with_mutual_inf(self, plot):
        name = plot + self.name + 'uncorrelated_index.csv'
        df = pandas.read_csv(name, sep=',', index_col=None)
        df = df.values
        return df

    # set the location for the uncorrelated_index file
    def data(self, MI_loc=''):
        if self.reg is False:
            x, y, row_shapes = self.get_features(self.path_to_features,
                                                 self.path_to_labels)
            y_cat = self.to_categorical(y, self.emotions)
            y_cat = np.argmax(y_cat, axis=1)
            y_cat = np.reshape(y_cat, (y_cat.shape[0], 1))
            y_cat = np.ravel(y_cat)
        else:
            x, y, row_shapes = self.get_features_regression(self.path_to_features,
                                                            self.path_to_labels)
        x = np.asarray(x)
        if self.MI is True:
            index = self.check_with_mutual_inf(MI_loc)
            index = index.T
            x = x[:, index[0]]
            print index[0]
            print x.shape[1]
        if self.reg is True:
            return x, y
        return x, y_cat


class Create_data_sets:
    def __init__(self, x, y, reg=False):
        self.reg = reg
        self.x = x
        self.y = y

    def create_val_set(self):
        x = np.array(self.x)
        y_cat = self.y
        permutation = np.random.permutation(x.shape[0])
        divide = 6
        # seperate with first validation
        step1 = x.shape[0] / divide
        x_perm = x[permutation, :]
        y_perm = y_cat[permutation]
        i0 = step1 * 5
        i1 = step1 * (5 + 1)
        x_final_test = x_perm[i0:i1]
        y_final_test = y_perm[i0:i1]
        x_perm = np.vstack((x_perm[:i0, :], x_perm[i1:, :]))
        x_final_train = np.vstack((x_perm[:i0, :], x_perm[i1:, :]))
        if self.reg is False:
            y_perm = np.append(y_perm[:i0], y_perm[i1:])
            y_final_train = np.append(y_perm[:i0], y_perm[i1:])
        elif self.reg is True:
            y_perm = np.vstack((y_perm[:i0], y_perm[i1:]))
            y_final_train = np.vstack((y_perm[:i0], y_perm[i1:]))
        parts = 5
        step = x_perm.shape[0] / parts

        return (x_perm, y_perm, x_final_test, y_final_test, parts, step,
                x_final_train, y_final_train)

    @staticmethod
    def create_cross_val_set(x_perm, y_perm, x_final_test,
                             y_final_test, part, step, reg=False):
        i0 = step * part
        i1 = step * (part + 1)
        x_train = np.vstack((x_perm[:i0, :], x_perm[i1:, :]))
        x_test = x_perm[i0:i1]
        y_test = y_perm[i0:i1]
        if reg is False:
            y_train = np.append(y_perm[:i0], y_perm[i1:])
        elif reg is True:
            y_train = np.vstack((y_perm[:i0], y_perm[i1:]))
        return x_train, x_test, y_train, y_test


class Plotting:
    def __init__(self):
        pass

    @staticmethod
    def plot_cross_val(number_of_components,  train, test, part,
                       plot, features):
        plt.figure(figsize=(30, 10))
        plt.plot(number_of_components,
                 train,
                 label='train')
        plt.plot(number_of_components,
                 test,
                 label='test')
        plt.title('PLS accuracy, fold number')
        plt.xlabel('number of components')
        plt.ylabel('PLS accuracy')
        plt.legend()
        plt.savefig(plot + features +
                    '_PLSR accuracy, number' + str(part) + '.png')
        plt.close()

    @staticmethod
    def plot_average(number_of_components,  acc_train_mean, acc_test_mean,
                     part, plot, features):
        plt.figure(figsize=(30, 10))
        plt.plot(number_of_components,
                 acc_train_mean,
                 label='train')
        plt.plot(number_of_components,
                 acc_test_mean,
                 label='test')
        plt.title('PLS-DA accuracy, fold number')
        plt.xlabel('number of components')
        plt.ylabel('PLS-DA accuracy')
        plt.legend()
        plt.savefig(plot + features + '_PLSR accuracy_average' + '.png')
        plt.close()


class PLSDA:
    def __init__(self, x, y, features, save, std=False, MI=False, reg=False):
        self.reg = reg
        self.dataset = Create_data_sets(x, y, reg=reg)
        self.feature = features
        (self.x_perm, self.y_perm, self.x_final_test,
         self.y_final_test, self.parts, self.step,
         self.x_final_train,
         self.y_final_train) = self.dataset.create_val_set()
        if features == 'nsynth':
            limit = 16
        elif features == 'pyaudio_more_cat' or features == 'pyaudio_less_cat':
            limit = 34
        else:
            limit = 100

        if MI is True:
            if features == 'nsynth':
                limit = 16
            elif features == 'pyaudio_more_cat' or features == 'pyaudio_less_cat':
                limit = 19
            elif features == 'mel_frequency_energy':
                limit = 53
            else:
                limit = 100

        if std is True:
            limit = 2 * limit

        self.limit = limit + 1

    def PLS_process(self, plot):
        PLSR_accuracy_train_total = []
        PLSR_accuracy_test_total = []
        for part in xrange(self.parts):
                print part
                PLSR_accuracy_train = []
                PLSR_accuracy_test = []

                x_train, x_test, y_train, y_test = self.dataset.create_cross_val_set(
                    self.x_perm, self.y_perm, self.x_final_test,
                    self.y_final_test, part, self.step, reg=self.reg)
                pp = Preprocessor('standard',
                                  n_components=20)
                (x_train, x_test) = pp.standardize(x_train, x_test)
                number_of_components = [i for i in range(1, self.limit)]
                for n in xrange(1, self.limit):
                    if n % 10 == 0:
                        print "at component " + str(n)
                    pls = PLSRegression(n_components=n, scale=False)
                    pls_fit = pls.fit(x_train, y_train)
                    if self.reg is False:
                        pred_train = np.round(np.ravel(pls_fit.predict(x_train)))
                        pred_test = np.round(np.ravel(pls_fit.predict(x_test)))
                        acc_train = pred_train[
                            pred_train ==
                            y_train].shape[0] / float(pred_train.shape[0])
                        acc_test = pred_test[pred_test ==
                                             y_test].shape[0] / float(pred_test.shape[0])
                    else:
                        acc_train = pls_fit.score(x_train, y_train)
                        acc_test = pls_fit.score(x_test, y_test)
                    PLSR_accuracy_train.append(acc_train)
                    PLSR_accuracy_test.append(acc_test)

                train = np.asarray(PLSR_accuracy_train)
                test = np.asarray(PLSR_accuracy_test)
                PLSR_accuracy_train_total.append(train)
                PLSR_accuracy_test_total.append(test)
                Plotting.plot_cross_val(number_of_components,  train, test,
                                        part, plot, self.feature)
        acc_train_mean = np.mean(np.asarray(PLSR_accuracy_train_total), axis=0)
        acc_test_mean = np.mean(np.asarray(PLSR_accuracy_test_total), axis=0)

        Plotting.plot_average(number_of_components,  acc_train_mean,
                              acc_test_mean, part,
                              plot, self.feature)


class feature_selection:
    def __init__(self, x, y, features, plot, reg=False):
        # standardize features
        scaler = StandardScaler()
        x = scaler.fit_transform(x)
        if reg is False:
            f_test, p_val = f_classif(x, y)
            f_test /= np.max(f_test)
            
            mi = mutual_info_classif(x, y)
            mi_not_scaled = mutual_info_classif(x, y)
            mi /= np.max(mi)

        pca = PCA()
        fit = pca.fit(x)
        # summarize components
        self.explained_variance = fit.explained_variance_
        self.explained_variance_ratio = fit.explained_variance_ratio_

        if reg is True:
                f_test_v, p_val_v = f_regression(x, y[:, 0])
                f_test_v /= np.max(f_test_v)
                
                f_test_a, p_val_a = f_regression(x, y[:, 1])
                f_test_a /= np.max(f_test_a)
                
                f_test_c = f_test_a + f_test_v
                f_test_c /= 2

                p_val_c = p_val_a + p_val_v
                p_val_c /= 2
                
                mi_v = mutual_info_regression(x, y[:, 0])
                mi_not_scaled = mi_v
                mi_v /= np.max(mi_v)

                mi_a = mutual_info_regression(x, y[:, 1])
                mi_a /= np.max(mi_a)
                mi_c = mi_a + mi_v
                mi_c /= 2
                mi = mi_c
                p_val = p_val_c
                f_test = f_test_c
        self.mi = mi
        self.mi_not_scaled = mi_not_scaled
        self.f_test = f_test
        self.p_val = p_val
        self.features = features
        self.x = x
        self.plot = plot

    def mutual_information(self):
        mi = self.mi
        features = self.features
        plot = self.plot
        if features == 'mel_frequency_energy':
            uncorrelated_index = np.where(mi < 0.9)
        elif features == 'opensmile_IS_09':
            uncorrelated_index = np.where(mi < 0.6)
        elif features == 'pyaudio_less_cat' or features == 'pyaudio_more_cat':
            uncorrelated_index = np.where(mi < 0.8)
        elif features == 'nsynth':
            uncorrelated_index = np.where(mi)
        elif features == 'combined_':
            uncorrelated_index = np.where(mi < 0.8)

        uncorrelated_index = np.ravel(uncorrelated_index)
        uncorrelated_index = pandas.DataFrame(uncorrelated_index)
        uncorrelated_index.iloc[:].to_csv(plot + features +
                                          'uncorrelated_index.csv',
                                          index=False, sep=',')
        uncorrelated_index.iloc[:].to_csv(plot + features +
                                          'uncorrelated_index.csv',
                                          index=False, sep=',')

    def plot_features(self):
        explained_variance = self.explained_variance
        explained_variance_ratio = self.explained_variance_ratio
        mi_not_scaled = self.mi_not_scaled
        f_test = self.f_test
        mi = self.mi
        p_val = self.p_val
        features = self.features
        plot = self.plot

        print 'explained_variance'
        print explained_variance
        print 'explained_variance ratio'
        print explained_variance_ratio

        x_axis = range(1, self.x.shape[1] + 1)
        plt.figure(figsize=(15, 5))
        plt.subplot(1, 3, 1)
        plt.scatter(x_axis, f_test)
        plt.xlabel("features")
        plt.title("F-values")

        plt.subplot(1, 3, 2)
        plt.scatter(x_axis, p_val)
        plt.xlabel("features")
        plt.title("p values")

        plt.subplot(1, 3, 3)
        plt.scatter(x_axis, mi)
        plt.xlabel("features")
        plt.title("mutual information scaled")

        plt.savefig(plot + features + 'F-test and MI classification.png')
        plt.close()

        plt.figure(figsize=(15, 5))
        plt.scatter(x_axis, mi_not_scaled)
        plt.xlabel("features")
        plt.title("mutual information")

        plt.savefig(plot + features + 'MI classification unscaled----.png')
        plt.close()

        plt.figure(figsize=(15, 5))
        plt.subplot(1, 2, 1)
        plt.scatter(x_axis, explained_variance)
        plt.xlabel("features")
        plt.title("explained_variance")

        plt.subplot(1, 2, 2)
        plt.scatter(x_axis, explained_variance_ratio)
        plt.xlabel("features")
        plt.title("explained_variance_ratio")
        plt.savefig(plot + features + 'explained_variance.png')
        plt.close()


def plot_factors(x, y, T_a, P_a, U_a, Q_a, features, plots,
                 feature_len, component_list):
    # plot scores
    # Scatter plot the scores of the first two factors.
    # I assume first two factors are all that matters

    plt.rcParams["figure.figsize"] = [6, 5]
    plt.scatter(T_a[:, 0], T_a[:, 1])
    plt.xlabel(r'$T_0$')
    plt.ylabel(r'$T_1$')
    plt.title('Score Plot (X-Scores)')
    plt.savefig(plots + features + 'Score_Plot_of_X-Scores' + '.png')
    plt.close()

    plt.scatter(P_a[:, 0], P_a[:, 1], marker='s', label='X-Loadings')
    plt.scatter(Q_a[:, 0], Q_a[:, 1], marker='v', label='Y-Loadings')
    # x columns
    plt.xlabel(r'$P_0$' + ' and ' r'$Q_0$')
    plt.xlabel(r'$P_1$' + ' and ' r'$Q_1$')
    plt.title('Loading Plot')
    plt.legend()
    plt.savefig(plots + features + 'Loading_Plot' + '.png')
    plt.close()

    clx = np.corrcoef(np.hstack((x, T_a[:, 0:2])).T)
    clx = clx[:feature_len, feature_len:]
    cly = np.corrcoef(np.hstack((y, T_a[:, 0:2])).T)
    cly = cly[:1, 1:]

    plt.figure(figsize=(30, 10))
    plt.scatter(clx[:, 0], clx[:, 1], marker='s', label='X')
    plt.scatter(cly[:, 0], cly[:, 1], marker='v', label='Y')
    # annotation is not helpful

    plt.plot(np.sin(np.linspace(0, 2 * np.pi, 100)),
             np.cos(np.linspace(0, 2 * np.pi, 100)), '--', color='.5')
    plt.plot(np.sqrt(0.5) * np.sin(np.linspace(0, 2 * np.pi, 100)),
             np.sqrt(.5) * np.cos(np.linspace(0, 2 * np.pi, 100)),
             '--', color='.8')
    plt.ylim(-1.1, 1.1)
    plt.xlim(-1.1, 1.1)
    plt.title('Correlation Loadings')
    plt.legend()
    plt.savefig(plots + features + 'Correlation_Loadings' + '.png')
    plt.close()

    pca = PCA(n_components=component_list)
    reduced = pca.fit_transform(x)

    # Plot a variable factor map for the first two dimensions.
    (fig, ax) = plt.subplots(figsize=(12, 12))
    for i in range(0, len(pca.components_)):
        plt.scatter(pca.components_[0, i], pca.components_[1, i], marker='s',
                    label='pca-components')
        plt.text(pca.components_[0, i] + 0.005,
                 pca.components_[1, i] + 0.005, str(i))

    # an = np.linspace(0, 0.1 * 2 * np.pi, 10)
    # Add a unit circle for scale
    # plt.plot(np.cos(an), np.sin(an))
    plt.axis('equal')
    ax.set_title('PCA components, just for first 2 dimensions')
    plt.savefig(plots + features + 'pca_components' + '.png')
    # plt.show()
    plt.close()

    print "runing sammon pca"
    # Run the Sammon projection
    sammon_pca, E = sammon(pca.components_, display=2)

    # Plot a variable factor map for the first two dimensions.
    (fig, ax) = plt.subplots(figsize=(12, 12))
    for i in range(0, len(sammon_pca)):
        plt.scatter(sammon_pca[i, 0], sammon_pca[i, 1], marker='s',
                    label='pca-components')
        plt.text(sammon_pca[i, 0] + 0.005,
                 sammon_pca[i, 1] + 0.005, str(i))

    # an = np.linspace(0, 0.1 * 2 * np.pi, 10)
    # Add a unit circle for scale
    # plt.plot(np.cos(an), np.sin(an))
    plt.axis('equal')
    ax.set_title('PCA components map with sammon')
    plt.savefig(plots + features + 'pca_components_sammon' + '.png')
    # plt.show()
    plt.close()

    # Plot a variable factor map for the first two dimensions.
    (fig, ax) = plt.subplots(figsize=(12, 12))
    T_a_transposed = np.transpose(T_a)
    for i in range(0, len(T_a_transposed)):
        plt.scatter(T_a_transposed[0, i], T_a_transposed[1, i], marker='s',
                    label='pls-components')
        plt.text(T_a_transposed[0, i] + 0.005,
                 T_a_transposed[1, i] + 0.005, str(i))

    # an = np.linspace(0, 0.1 * 2 * np.pi, 10)
    # Add a unit circle for scale
    # plt.plot(np.cos(an), np.sin(an))
    plt.axis('equal')
    ax.set_title('transposed Variable factor map, just for fist 2 dimensions')
    plt.savefig(plots + features + 'pls_components' + '.png')
    # plt.show()
    plt.close()

    # Run the Sammon projection
    print "runing sammon Transposed T_a"
    T_a_sammon, E = sammon(T_a, display=2)

    # Plot a variable factor map for the first two dimensions.
    (fig, ax) = plt.subplots(figsize=(12, 12))
    for i in range(0, len(T_a_sammon)):
        plt.scatter(T_a_sammon[i, 0], T_a_sammon[i, 1], marker='s',
                    label='pls-components')

    plt.axis('equal')
    ax.set_title('transposed Variable factor map with sammon')
    plt.savefig(plots + features + 'pls_components_sammon' + '.png')
    # plt.show()
    plt.close()


class final_test:
    def __init__(self):
        pass

    @staticmethod
    def plot(x, y, features, plot, component_list, reg=False):
        split_set = Create_data_sets(x, y, reg)
        (x_perm, y_perm, x_final_test, y_final_test, parts, step,
         x_final_train, y_final_train) = split_set.create_val_set()
        pp = Preprocessor('standard',
                          n_components=20)
        (x_final_train, x_final_test) = pp.standardize(
            x_final_train, x_final_test)

        print "at component " + str(component_list)
        pls = PLSRegression(n_components=component_list, scale=False)
        pls_fit = pls.fit(x_final_train, y_final_train)
        if reg is False:
            pred_train = np.round(np.ravel(pls_fit.predict(x_final_train)))
            pred_test = np.round(np.ravel(pls_fit.predict(x_final_test)))
            acc_train = pred_train[pred_train ==
                                   y_final_train].shape[0] / float(pred_train.shape[0])
            acc_test = pred_test[pred_test ==
                                 y_final_test].shape[0] / float(pred_test.shape[0])
        else:
            acc_train = pls_fit.score(x_final_train, y_final_train)
            acc_test = pls_fit.score(x_final_test, y_final_test)

        with open(plot + features + 'final_accuracy.csv', 'w') as csvfile:
            w = csv.writer(csvfile, delimiter=',')
            w.writerow(str(component_list))
            w.writerow(['final train_accuracy', acc_train])
            w.writerow(['final test_accuracy', acc_test])

        pls_a = PLSRegression(n_components=component_list)
        pls_a.fit(x, y)
        T_a = pls_a.x_scores_
        P_a = pls_a.x_loadings_
        U_a = pls_a.y_scores_
        Q_a = pls_a.y_loadings_
        if reg is False:
            y = np.reshape(y, (y.shape[0], 1))
        plot_factors(x, y, T_a, P_a, U_a, Q_a, features, plot,
                     x_perm.shape[1], component_list)
