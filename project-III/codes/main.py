###########################################################
## Imports
###########################################################
from random import randint
from math import *
import numpy

###########################################################
## Functions
###########################################################

def readDistanceMatrix(fileName):
  file = open('../input/'+fileName, 'r')
  matrix = []
  matrix = [ line.split() for line in file ]
  for i in range(len(matrix)):
    for j in range(len(matrix[i])):
      matrix[i][j] = int(matrix[i][j])
  anotherMatrix = createMatrix(len(matrix), len(matrix[0]), 0)

  #filling upper diagonal
  for i in range(len(anotherMatrix)):
    for j in range(i, len(anotherMatrix[0])):
      anotherMatrix[i][j] = matrix[i][j-i]

  #filling simetrical diagonal
  for i in range(len(anotherMatrix)):
    for j in range(i):
      anotherMatrix[i][j] = anotherMatrix[j][i]
  return anotherMatrix

def readEuclideanMatrix(fileName):
  file = open('../input/'+fileName, 'r')
  euclideanPointsMatrix= []
  euclideanPointsMatrix= [ line.split() for line in file ]
  for i in range(len(euclideanPointsMatrix)):
    for j in range(len(euclideanPointsMatrix[i])):
      euclideanPointsMatrix[i][j] = float(euclideanPointsMatrix[i][j])

  matrix = createMatrix(len(euclideanPointsMatrix), len(euclideanPointsMatrix), 0)

  for i in range(len(euclideanPointsMatrix)):
    for j in range(len(euclideanPointsMatrix)):
      matrix[i][j] = sqrt(pow(euclideanPointsMatrix[i][0]-euclideanPointsMatrix[j][0],2) + pow(euclideanPointsMatrix[i][1]-euclideanPointsMatrix[j][1],2))
  return matrix

def createMatrix(lin, col, initialValue):
  matrix = []
  for i in range(lin):
    matrix.append( [initialValue] * col )
  return matrix

def startAnt(matrix):
  for i in range(len(matrix)):
    matrix[i][i] = 1
  return matrix

def calculeProbability(probMatrix, pathMatrix, pheromMatrix, distMatrix):
  for i in range(len(probMatrix)):
    for j in range(len(probMatrix[0])):
      if(pathMatrix[i][j] == 0):
        probMatrix[i][j] = probij(pheromMatrix, distMatrix, i, j)
  return probMatrix

def probij(pheromMatrix, distMatrix, i, j):
  sum = 0
  Alfa = 1
  Beta = 3
  for k in range(len(pheromMatrix[0])):
    if(pathMatrix[i][k] == 0):
      sum += (pow(pheromMatrix[i][k],Alfa) * (pow((1.0/distMatrix[i][k]),Beta)))
  return (pow(pheromMatrix[i][j],Alfa) * (1.0/pow(distMatrix[i][j],Beta))) / sum

def draftNextCity(probMatrix, pathMatrix):
  #print probMatrix
  lista = []
  vetCity = range(len(probMatrix))
  for i in range(len(probMatrix)):
    number = randint(1,999)/1000.0
    #print
    #print number
    lista.append(number)
    vet = range(len(probMatrix[i]))
    vet[0] = probMatrix[i][0]

    for v in range(1,len(vet)):
      vet[v] = vet[v-1]+probMatrix[i][v]
    #print vet
    for v in range(len(vet)):
      if number <= vet[v]:
        #print "pos:" + str(v)
        vetCity[i] = v
        break
  return vetCity

def fillPathMatrix(vetCity, pathMatrix):
  for i in range(len(pathMatrix)):
    aux = max(pathMatrix[i])
    pathMatrix[i][vetCity[i]] = aux + 1
  return pathMatrix

def sub(distanceMatrix, pathMatrix, pheromoneMatrix):
  for i in range(len(distanceMatrix)-1):
    probabilityMatrix = createMatrix(len(distanceMatrix), len(distanceMatrix[0]), 0)
    probabilityMatrix = calculeProbability(probabilityMatrix, pathMatrix, pheromoneMatrix, distanceMatrix)
    vetCity = draftNextCity(probabilityMatrix, pathMatrix)
    pathMatrix = fillPathMatrix(vetCity, pathMatrix)
  return pathMatrix

def calculateFinalDistance(pathMatrix, distanceMatrix):
  vet = range(len(distanceMatrix))
  for i in range(len(pathMatrix)):
    lista = []
    for k in range(1,len(pathMatrix)+1):
      for j in range(len(pathMatrix[i])):
        if pathMatrix[i][j] == k:
          lista.append(j)
    lista.append(lista[0])
    vet[i] = 0#distanceMatrix[i][lista[0]]
    for z in range(1,len(lista)):
      vet[i] += distanceMatrix[lista[z-1]][lista[z]]

  return vet

def calculatePheromone(pathMatrix, pheromoneMatrix, distanceVector, p, Q):
  for i in range(len(pheromoneMatrix)):
    for j in range(len(pheromoneMatrix[0])):
      pheromoneMatrix[i][j] = (1-p) * pheromoneMatrix[i][j] + verifyPheromone(i,j, Q, pathMatrix, distanceVector)
  return pheromoneMatrix


def verifyPheromone(i,j,Q, pathMatrix, distanceVector):
  sum = 0.0
  for k in range(len(pathMatrix)):
    aux = abs(pathMatrix[k][i] - pathMatrix[k][j])
    if(aux == 1):
      sum += (Q*1.0)/distanceVector[k]
  return sum

def verifyPaths(pathMatrix):
  vet = range(len(pathMatrix))
  for i in range(len(pathMatrix)):
    lista = []
    for k in range(1,len(pathMatrix)+1):
      for j in range(len(pathMatrix[i])):
        if pathMatrix[i][j] == k:
          lista.append(j)
    lista.append(lista[0])
    vet[i] =  lista

  for i in range(1,len(vet[0])):
    aux = 0
    for j in range(1,len(vet)):
      for k in range(1,len(vet[0])):
        if((vet[j][k-1] == vet [0][i-1] and vet[j][k] == vet[0][i]) or (vet[j][k-1] == vet [0][i] and vet[j][k] == vet[0][i-1])):
          aux += 1
          break
    if (aux != len(vet)-1):
      return -1

  return 1
###########################################################
## Code
###########################################################
##Variables
P = 0.9 ##evaporation of pheromone
Q = 1 ##deposit of pheromone
K = 50 ##number of executions
I = 100 ##number of iterations
###########################################################
#distanceMatrix = readDistanceMatrix("M6")
distanceMatrix = readEuclideanMatrix("M15")
pheromoneMatrix = createMatrix(len(distanceMatrix), len(distanceMatrix[0]), 1)
listaMinDistance = []
for k in range(K):
  for i in range(I):
    pathMatrix = createMatrix(len(distanceMatrix), len(distanceMatrix[0]), 0)
    pathMatrix = startAnt(pathMatrix)
    pathMatrix = sub(distanceMatrix, pathMatrix, pheromoneMatrix)
    distanceVector = calculateFinalDistance(pathMatrix, distanceMatrix)
    pheromoneMatrix = calculatePheromone(pathMatrix, pheromoneMatrix, distanceVector, P, Q)
    #print pheromoneMatrix
    #print pathMatrix
    if(verifyPaths(pathMatrix) == 1):
      break

  minDistance = min(distanceVector)
  for i in range(len(distanceVector)):
    if(distanceVector[i] == minDistance):
      lista = []
      for z in range(1,len(pathMatrix)+1):
        for j in range(len(pathMatrix[i])):
          if pathMatrix[i][j] == z:
            lista.append(j)
      lista.append(lista[0])
      print "\nCaminho:" + str(k)
      print "Total distance path: "+str(minDistance)

      print lista
      #print pathMatrix[i]
      listaMinDistance.append(minDistance)
      break

print "\n\nP: " + str(P) + "\tI: " +str(I)
print "Melhor: " + str(min(listaMinDistance))
print "Pior: " + str(max(listaMinDistance))
print "Media: " + str(numpy.mean(listaMinDistance))
print "\a"
