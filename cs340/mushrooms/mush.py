# File: mush.py
# Date: Nov. 13, 2019
# Author: Adam Abad
# Purpose: To parse a file of mushrooms and predict if unknown mushrooms are
#   edible or poisonous. 

# Resources Used: https://scikit-learn.org/stable/modules/generated/sklearn.naive_bayes.GaussianNB.html
# https://pandas.pydata.org/pandas-docs/stable/

import pandas as pd
from sklearn.naive_bayes import GaussianNB

def makeTable(data):
	col_Names = [
		"edible", #0
		"capshape", #1
		"capsurface", #2
		"capcolor", #3
		"bruises", #4
		"odor", #5
		"gillattachment", #6
		"gillspacing", #7
		"gillsize", #8
		"gillcolor", #9
		"stalkshape", #10	
		"stalkroot", #11
		"stalksurfaceabovering", #12
		"stalksurfacebelowring", #13
		"stalkcolorabovering", #14
		"stalkcolorbelowring", #15
		"veiltype", #16
		"veilcolor", #17
		"ringnumber", #18
		"ringtype", #19
		"sporeprintcolor", #20
		"population", #21
		"habitat" #22
	]
	data.columns = col_Names
	
	data['edible'] = data.edible.map({'e' : 0, 'p' : 1})
	data['capshape'] = data.capshape.map({'b':1,'c':2,'x':3,'f':4,'k':5,'s':6})
	data['capsurface'] = data.capsurface.map({'f':1,'g':2,'y':3,'s':4})
	data['capcolor'] = data.capcolor.map({'n':1,'b':2,'c':3,'g':4,'r':5,'p':6,'u':7,'e':8,'w':9,'y':10})
	data['bruises'] = data.bruises.map({'t':1,'f':0})
	data['odor'] = data.odor.map({'a':1,'l':2,'c':3,'y':4,'f':5,'m':6,'n':0,'p':7,'s':8})
	data['gillattachment'] = data.gillattachment.map({'a':1,'d':2,'f':3,'n':4})
	data['gillspacing'] = data.gillspacing.map({'c':1,'w':2,'d':3})
	data['gillsize'] = data.gillsize.map({'b':1,'n':2})
	data['gillcolor'] = data.gillcolor.map({'k':1,'n':2,'b':3,'h':4,'g':5,'r':6,'o':7,'p':8,'u':9,'e':10,'w':11,'y':12})
	data['stalkshape'] = data.stalkshape.map({'e':1,'t':2})
	data['stalkroot'] = data.stalkroot.map({'b':1,'c':2,'u':3,'e':4,'z':5,'r':6,'?':0})
	data['stalksurfaceabovering'] = data.stalksurfaceabovering.map({'f':1,'y':2,'k':3,'s':4})
	data['stalksurfacebelowring'] = data.stalksurfacebelowring.map({'f':1,'y':2,'k':3,'s':4})
	data['stalkcolorabovering'] = data.stalkcolorabovering.map({'n':1,'b':2,'c':3,'g':4,'o':5,'p':6,'e':7,'w':8,'y':9})
	data['stalkcolorbelowring'] = data.stalkcolorbelowring.map({'n':1,'b':2,'c':3,'g':4,'o':5,'p':6,'e':7,'w':8,'y':9})
	data['veiltype'] = data.veiltype.map({'p':1,'u':2})
	data['veilcolor'] = data.veilcolor.map({'n':1,'o':2,'w':3,'y':4})
	data['ringnumber'] = data.ringnumber.map({'n':0,'o':1,'t':2})
	data['ringtype'] = data.ringtype.map({'c':1,'e':2,'f':3,'l':4,'n':0,'p':5,'s':6,'z':7})
	data['sporeprintcolor'] = data.sporeprintcolor.map({'k':1,'n':2,'b':3,'h':4,'r':5,'o':6,'u':7,'w':8,'y':9})
	data['population'] = data.population.map({'a':1,'c':2,'n':3,'s':4,'v':5,'y':6})
	data['habitat'] = data.habitat.map({'g':1,'l':2,'m':3,'p':4,'u':5,'w':6,'d':7})
	return data
	
file = raw_input('Enter the file to train the program with: ')
traindata = pd.read_csv(file,header = 0)
traindata = makeTable(traindata)

clf = GaussianNB()
clf.fit(traindata.drop(['edible'],axis=1),traindata['edible'])

file = raw_input('Enter the file to test the program with: ')
testdata = pd.read_csv(file,header = 0)
testdata = makeTable(testdata)

poisontotal = 0
edibletotal = 0
poisoncorrect = 0
ediblecorrect = 0

for index, row in testdata.iterrows():
	guess = clf.predict([row.drop(['edible'])])
	result = row['edible']
	if(result == 1):
		if(result == guess):
			poisoncorrect = poisoncorrect + 1
		poisontotal = poisontotal + 1
	else:
		if(result == guess):
			ediblecorrect = ediblecorrect + 1
		edibletotal = edibletotal + 1
		
perEd = float(ediblecorrect) / int(edibletotal) * 100
perPoi = float(poisoncorrect) / int(poisontotal) * 100

print 'Correctly identified {0} of {1} poisonous mushrooms - {2:.2f}% accurate'.format(poisoncorrect, poisontotal, perPoi)
print 'Correctly identified {0} of {1} edible mushrooms    - {2:.2f}% accurate'.format(ediblecorrect,edibletotal, perEd)
