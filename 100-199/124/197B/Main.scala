import java.util.Scanner

object Main {

   def main(args: Array[String]): Unit = {
      val scanner = new Scanner (System.in)
		val n, m = scanner nextInt ()
		val p = (for (i <- 0 to n) yield scanner nextInt ()) toList
		val q = (for (i <- 0 to m) yield scanner nextInt ()) toList

		if (n > m) {
			if (p(0) * q(0) < 0) print ("-")
			println ("Infinity")
		} else if (n < m) {
			println ("0/1")
		} else {
			val pp = math.abs (p(0))
			val qq = math.abs (q(0))
			val s = if (p(0) * q(0) > 0) 1 else -1
			val g = gcd (pp, qq)
			print (s * pp / g)
			print ("/")
			println (qq / g)
		}
   }

	def gcd(x: Int, y: Int): Int = {
		if (y == 0) x else gcd (y, x%y)
	}

}
