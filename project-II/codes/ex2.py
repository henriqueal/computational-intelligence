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
  
def train(weightMatrix, inputMatrix, neuronio):
  epoch = -1
  cont = 0
  for fimEpoca in range(1000):
    for j in range(2):
      sum = 0
      for i in range(31):
        sum = sum + (weightMatrix[neuronio][i] * inputMatrix[j][i])
      if(sum <= 0 and neuronio == j):
        weightMatrix = addWeights(weightMatrix, inputMatrix, neuronio, j)
        epoch = j
        cont = cont +1
      elif(sum > 0 and neuronio !=j):
        weightMatrix = subWeights(weightMatrix, inputMatrix, neuronio, j) 
        epoch = j
        cont = cont +1
      else:
        if(epoch == j):
          print "fimEpoca"+str(fimEpoca)
          return weightMatrix
  return weightMatrix

def match(testsMatrix, weightMatrix):
  vet = range(2)
  for i in range(2):
    sum = 0
    for j in range(31):
      sum = sum + (weightMatrix[i][j] * testsMatrix[j])
    if(sum > 0):
      vet[i] = 1
    else:
      vet[i] = 0
  return vet

def fillRandom(matrix):
  for i in range(6):
    for j in range(31):
      matrix[i][j] = randrange(-1,2)
  return matrix

#criando arquivo de entrada
inputMatrix = createMatrix(2,31)
inputMatrix = fillMatrix(inputMatrix)
for i in range(2):
  inputMatrix[i][30]=1
  
#criando a matriz de pesos
weightMatrix = createMatrix(2,31)
#weightMatrix = fillRandom(weightMatrix)

#criando a matriz de testes
testMatrix = createMatrix(60,31)
testMatrix = fillMatrixTest(testMatrix)
for i in range(60):
  testMatrix[i][30]=1

#treinando os neuronios
for i in range(2): 
  weightMatrix = train(weightMatrix, inputMatrix, i)

#imprimindo os pesos
for i in range(2):
  printInput(weightMatrix[i])

#fazendo os testes
for i in range(60):
  print str(i/10)+str(i%10)+'.txt'
  print match(testMatrix[i], weightMatrix)



