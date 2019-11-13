#ifndef QUENE_H_INCLUDED
#define QUENE_H_INCLUDED


const int MaxQsize=2000;

template <class T>
class Quene
{

  private:
      int front;   // QUENE ARRAY AND ITS PARAMETERS
      int rear;
      int count;
      T qlist[MaxQsize];

  public:
      Quene(void);     // CONSTRRUCTOR
      void QInsert(const T& item);  // QUENE INSERT OPERATION
      T QDelete(void);              // QUENE DELETE OPERATION
      void ClearQ(void);
      T PeekQueue(void) ;           // QUENE TEST METHODS
      int QLength(void) const;
      int QEmpty(void) const;
      int QFull(void) const;

};


#endif // QUENE_H_INCLUDED
