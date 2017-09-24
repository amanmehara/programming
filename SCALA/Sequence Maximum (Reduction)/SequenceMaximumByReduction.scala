/**
  * Created by @amanmehara on 24-09-2017.
  */
object SequenceMaximumByReduction {

  def maximumByReduction (numbers: List[Int]): Int = {
    numbers.reduceLeft(_ max _)
  }

}
