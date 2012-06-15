import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		val n, m = scanner nextInt ()
		val map = (for (i <- 1 to n) yield scanner next ()) toArray
		val ans = solve(map)
		println (if (ans) "Yes" else "No")
	}

	def search(map: Array[String], c: Char): (Int, Int) = {
		var ret = (-1, -1)
		for (i <- 0 to map.length - 1; j <- 0 to map(i).length - 1) {
			if (map(i)(j) == c) {
				ret = (i, j)
			}
		}
		ret
	}

	def solve(map: Array[String]): Boolean = {
		val s = search(map, 'S')
		val n = map length
		val m = map(0) length
		val memo = Array.tabulate (n, m) ((_, _) => None: Option[(Int, Int)])
		var t = 0
		def solve2(pos: (Int, Int)): Boolean = {
			val (xx, yy) = mod (pos)
			if (map(xx)(yy) == '#') {
				false
			} else if (memo(xx)(yy) != None) {
				memo(xx)(yy) != Some (pos)
			} else {
				memo(xx)(yy) = Some (pos)
				var ret = false
				for (npos <- adj (pos)) {
					ret |= solve2(npos)
				}
				ret
			}
		}
		def mod(pos: (Int, Int)): (Int, Int) = {
			val (x, y) = pos
			((x % n + n) % n, (y % m + m) % m)
		}
		def adj(pos: (Int, Int)): List[(Int, Int)] = {
			val (x, y) = pos
			val dxys = List((1, 0), (0, 1), (-1, 0), (0, -1))
			for ((dx, dy) <- dxys) yield (x + dx, y + dy)
		}

		solve2(s)
	}

}
