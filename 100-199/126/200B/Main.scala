import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		val n = scanner nextInt ()
		val p = List.tabulate (n) (i => scanner nextInt ())
		val ans = (p.sum: Double) / n
		println (ans)
	}

}
