from random import randrange
def readFile(fileName):
  file = open('../input/'+fileName, 'r')
  content = file.read()
  file.close()
  input = range(31)
  input[30] = 0
  for i in range(30):
    input[i] = int(content[i * 2])  
  return input
  
def createMatrix(lin, col):
  matrix = []
  for i in range(lin):
    matrix.append( [0] * col )
  return matrix

def fillMatrix(matrix):
  for i in range(2):
    matrix[i] = readFile(str(i)+'.txt')
  return matrix

def fillMatrixTest(matrix):
  for i in range(6):
    for j in range(10):
      matrix[(i*10)+j] = readFile('../tests/'+str(i)+str(j)+'.txt')
  return matrix
    
  
def printInput(matrix):
    s=""
    for j in range(31):
      if((j%5) == 0):
        print s
        s = ""
      s = s+str(matrix[j]) + " "  
    print "w="+str(matrix[30]) 

def printInput2(matrix):
  for i in range (60):
    s=""
    for j in range(31):
      if((j%5) == 0):
        print s
        s = "" 
      s = s+str(matrix[i][j]) + " " 

def addWeights(weightMatrix, matrix, neuronio, indexMatrix):
  for i in range(len(weightMatrix[0])):
    weightMatrix[neuronio][i] = weightMatrix[neuronio][i] + matrix[indexMatrix][i]
  return weightMatrix

def subWeights(weightMatrix, matrix, neuronio, indexMatrix):
  for i in range(len(weightMatrix[0])):
    weightMatrix[neuronio][i] = weightMatrix[neuronio][i] - matrix[indexMatrix][i]
  return weightMatrix
  
def train(weightMatrix, inputMatrix):
  epoch = -1
  cont = 0
  for fimEpoca in range(1000):
    for j in range(2):
      sum = 0
      for i in range(31):
        sum = sum + (weightMatrix[0][i] * inputMatrix[j][i])
      if(sum <= 0 and j == 1):
        weightMatrix = addWeights(weightMatrix, inputMatrix, 0, j)
        epoch = j
        cont = cont +1
      elif(sum > 0 and j== 0 ):
        weightMatrix = subWeights(weightMatrix, inputMatrix, 0, j) 
        epoch = j
        cont = cont +1
      else:
        if(epoch == j):
          print "fimEpoca"+str(fimEpoca)
          return weightMatrix
  return weightMatrix

def match(testsMatrix, weightMatrix):
  vet = range(1)
  sum = 0
  for j in range(31):
    sum = sum + (weightMatrix[0][j] * testsMatrix[j])
  if(sum > 0):
    vet[0] = 1
  else:
    vet[0] = 0
  return vet

def fillRandom(matrix):
  for i in range(len(matrix)):
    matrix[i] = randrange(-1,2)
  return matrix

#criando arquivo de entrada
inputMatrix = createMatrix(2,31)
inputMatrix = fillMatrix(inputMatrix)
for i in range(2):
  inputMatrix[i][30]=1
  
#criando a matriz de pesos
weightMatrix = createMatrix(1,31)
weightMatrix[0] = fillRandom(weightMatrix[0])

#criando a matriz de testes
testMatrix = createMatrix(60,31)
testMatrix = fillMatrixTest(testMatrix)
for i in range(60):
  testMatrix[i][30]=1

#treinando os neuronios
weightMatrix = train(weightMatrix, inputMatrix)

#imprimindo os pesos
printInput(weightMatrix[0])

#fazendo os testes
for i in range(60):
  print str(i/10)+str(i%10)+'.txt'
  print match(testMatrix[i], weightMatrix)



