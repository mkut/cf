import java.util.Scanner

object Main {

   def main(args: Array[String]): Unit = {
       val scanner = new Scanner (System.in)
		 val n, m = scanner.nextInt()
		 val ansList = List.iterate ((m + 1) / 2, m) { i =>
			 if (i <= m / 2) m - i + 1 else m - i
		 }
		 val ans = ansList.toArray
		 for (i <- 0 to n-1) {
			 println (ans(i%m))
		 }
   }

}
