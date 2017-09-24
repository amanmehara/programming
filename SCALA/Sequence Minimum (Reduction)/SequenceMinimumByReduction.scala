/**
  * Created by @amanmehara on 24-09-2017.
  */
object SequenceMinimumByReduction {

  def minimumByReduction (numbers: List[Int]): Int = {
    numbers.reduceLeft(_ min _)
  }

}
