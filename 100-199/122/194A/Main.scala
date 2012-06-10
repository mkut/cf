import java.util.Scanner
import math.min
import math.max

object Main {

    def main(args:Array[String]) {
        val scanner = new Scanner(System.in)
        val n, k = scanner.nextInt()
        val ans = max (0, min (n, 3 * n - k))
        println (ans)
    }

}

// vim: set ts=4 sw=4 et:
