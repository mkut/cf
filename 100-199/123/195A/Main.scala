import java.util.Scanner

object Main {

   def main(args: Array[String]): Unit = {
       val scanner = new Scanner (System.in)
		 val a, b, c = scanner.nextInt()
		 val ans = (a * c + b - 1) / b - c
		 println (ans)
   }

}
