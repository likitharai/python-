import numpy as np
arr2=np.array(list(range(1,31)))
print(arr2)
arr2[arr2%2==0]=-1
print(arr2)