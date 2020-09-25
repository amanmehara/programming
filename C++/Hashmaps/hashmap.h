#include<string>
#include<stdio.h>
using namespace std;
template <class V>

class mapNode{
  public: 
  string key;
  V value;
  mapNode *next;

  mapNode(string key,V value){
    this->key = key;
    this->value = value;
    next = NULL;
  }

  ~mapNode(){
    delete next;
  }
};
 
template <class V>
class ourmap
{
  mapNode<V> **buckets;
  int count; 
  int numBuckets;

  public:
  ourmap(){
     count = 0;
    numBuckets = 5;
    buckets = new mapNode<V> *[numBuckets];

    for (int i = 0; i < numBuckets;i++)
    {
      buckets[i] = NULL;
    }
  }
  ~ourmap() {
    for (int i = 0; i < numBuckets;i++)
    {
      delete buckets[i];
    }
    delete[] buckets;
  }

// occupied in bucket array
int size(){
  return count;
}

// get value corresponding to key
V getValue(string key){
int bucketIndex = getBucketIndex(key);
 mapNode<V> *head = buckets[bucketIndex]; 
 while(head!=NULL)
 {
   if(head->key==key)
     return head->value;

   head = head->next;
 }
 return 0;
}

// hashcode and compression function
private:
int getBucketIndex(string key){
  int hashCode=0;

  int currentCoefficient = 1;
  for (int i = key.length() - 1; i >= 0;i--)
  {
    hashCode += key[i] * currentCoefficient;
    hashCode = hashCode % numBuckets;
    currentCoefficient *= 37;
    currentCoefficient = currentCoefficient % numBuckets;
  }
    return hashCode % numBuckets;
}

// rehashing function
void rehash(){
  mapNode<V> **temp = buckets;
  buckets = new mapNode<V> *[2 * numBuckets];
  for (int i = 0; i < 2 * numBuckets;i++)
  {
    buckets[i] = NULL; 
  }
  int oldBucketCount = numBuckets;
  numBuckets *= 2;
  count = 0;

  for (int i = 0; i < oldBucketCount;i++)
  {
    mapNode<V> *head = temp[i];
    while(head!=NULL)
    {
      string key = head->key;
      V value = head->value;
      insert(key, value);
      head = head->next;
    }
  }

  for (int i = 0; i < oldBucketCount;i++)
  {
     mapNode<V> *head = temp[i];
     delete head;
  }
  delete[] temp;
}

public:
double getLoadFactor(){
  return (1.0 * count) / numBuckets; 
}

// inserting element
void insert(string key, V value){
  int bucketIndex = getBucketIndex(key);
  mapNode<V> *head = buckets[bucketIndex]; 
  while(head!=NULL)
  {
    if(head->key==key)
    {
      head->value = value;
      return;
    
    }
    head = head->next; 
  }
head = buckets[bucketIndex];
mapNode<V> *node = new mapNode<V>(key, value);

node->next = head;
buckets[bucketIndex] = node;

count++;

//rehashing
double loadfactor = (1.0 * count) / numBuckets;
if(loadfactor>0.7)
  rehash();
}

// remove the element
V remove(string key){
  int bucketIndex = getBucketIndex(key);
  mapNode<V> *head = buckets[bucketIndex];
  mapNode<V> *prev = NULL; 

  while(head!=NULL)
  {
    if(head->key==key)
    { if(prev==NULL)
        buckets[bucketIndex] = head->next ;
      else
        prev->next = head->next;

      V value = head->value;
      head->next = NULL;
      delete head;
      count--;
      return value;
    }
    prev = head;
    head = head->next;
  }
  return 0;
}
};
