import numpy as np
a = np.array([[1, 8, 3],
              [2, 9, 4],
              [3, 5, 2]])
a[a>5]=0
print(a)