import pandas as pd
import numpy as np
data=pd.DataFrame({'name':['anu','vishal','ravi'],'marks':[85,92,78],'gender':['f','m','m']})
data['result']=np.where(data['marks']>80,'pass','fail')
Average=np.average(data['marks'])
print(data)
print(f'Average marks is {Average}')