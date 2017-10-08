object SequenceMinimumByReduction {

  def minimumByReduction(numbers: List[Int]): Int = {
    numbers.reduceLeft(_ min _)
  }

}