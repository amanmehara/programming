object SequenceMaximumByReduction {

  def maximumByReduction(numbers: List[Int]): Int = {
    numbers.reduceLeft(_ max _)
  }

}