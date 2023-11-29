#include "sequence.hpp"
#include <limits>

likhachev::SequenceLocalMaxCount::SequenceLocalMaxCount():
  currValue(0),
  count(0),
  localMaxCount(0),
  localMax(std::numeric_limits< int >::min())
{}

void likhachev::SequenceLocalMaxCount::operator()(int newNumber)
{
  currValue = newNumber;
  count++;
  checkLocalMax();
}

int likhachev::SequenceLocalMaxCount::operator()() const
{
  return localMaxCount;
}

void likhachev::SequenceLocalMaxCount::checkLocalMax()
{
  if (currValue > localMax) {
    localMax = currValue;
    localMaxCount = 0;
  }
  if (currValue == localMax) {
    localMaxCount++;
  }
}

int likhachev::SequenceLocalMaxCount::getCount() const
{
  return count;
}

likhachev::SequenceSignChangeCount::SequenceSignChangeCount():
  currValue(0),
  count(0),
  singChangeCount(0)
{}

void likhachev::SequenceSignChangeCount::operator()(int newNumber)
{
  checkSamgeSign(newNumber);
  currValue = newNumber;
  count++;
}

int likhachev::SequenceSignChangeCount::operator()() const
{
  return singChangeCount;
}

void likhachev::SequenceSignChangeCount::checkSamgeSign(int newNumber)
{
  if (newNumber * currValue < 0) {
    singChangeCount++;
  }
}

int likhachev::SequenceSignChangeCount::getCount() const
{
  return count;
}
