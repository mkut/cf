import java.util.Scanner

object Main {

   def main(args: Array[String]): Unit = {
      val scanner = new Scanner (System.in)
		val str = scanner nextLine () reverse

		println (solve (str) reverse)
   }

	def solve(str: String): String = {
		var prev = 0
		def f(c: Char): Boolean = {
			if (prev <= c) {
				prev = c
				true
			} else false
		}
		str filter f
	}

}
