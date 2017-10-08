object SequenceSumByReduction {

  def sumByReduction(numbers: List[Int]): Int = {
    numbers.reduceLeft(_ + _)
  }

}