import numpy as np

class SVM:
    
    def __init__(self, learning_rate=0.01, lambda_param=0.01, n=1000):
        self.lr = learning_rate
        self.lambda_param = lambda_param
        self.n = n
        self.w = None
        self.b = None
    
    def fit(self, X,y):
        pass
    def predict(self, X, y):
        