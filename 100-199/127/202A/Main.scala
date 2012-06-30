import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		val s = scanner.next ()
		val t = s.sorted.reverse
		val ans = t.takeWhile(c => c == t.head)
		println (ans)
	}

}
