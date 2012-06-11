import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		val t = scanner.nextInt()
		for (i <- 1 to t) {
			val n = scanner.nextLong()
				println (solve (n))
		}
	}

	def solve(n: Long): Long = {
		4*n / gcd(4*n, n+1) + 1
	}

	def gcd(x: Long, y: Long): Long = {
		if (y == 0) x else gcd (y, x % y)
	}

}
