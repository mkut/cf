import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		val x1, y1, r1, R1, x2, y2, r2, R2 = scanner nextInt ()
		val circles = List ((x1, y1, r1), (x1, y1, R1), (x2, y2, r2), (x2, y2, R2))
		val circles2 = List ((circles (0), circles(1)), (circles(2), circles(3)))
		val ans = circles count (x => (circles forall (y => f (x, y) != -1)) && (circles2 forall (g (x))))
		println (ans)
	}

	def f(v1: (Int, Int, Int), v2: (Int, Int, Int)): Int = {
		val (x1, y1, r1) = v1
		val (x2, y2, r2) = v2
		val d = sqr (x1-x2) + sqr (y1-y2)
		val d1 = sqr (r1+r2)
		val d2 = sqr (r1-r2)
		if (d == 0 && d2 == 0) 0
		else if (d >= d1) 1
		else if (d > d2) -1
		else if (r1 > r2) 2
		else -2
	}

	def g(v1: (Int, Int, Int))(v2: ((Int, Int, Int), (Int, Int, Int))): Boolean = {
		val (v3, v4) = v2
		if (v3 == v1 || v4 == v1) true
		else if (f (v1, v3) != -2 && f (v4, v1) == 2) false else true
	}

	def sqr(x: Int): Int = {
		x * x
	}

}
