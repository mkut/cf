import java.util.Scanner

object Main {

	def main(args: Array[String]): Unit = {
		val scanner = new Scanner (System.in)
		for (i <- 1 to 5) read (scanner)
		for (team <- teams.values) {
			val (n, p, d, g, name) = team
			if (n < 3 && name != "BERLAND") enemy = name
		}

		val berland = teams("BERLAND")
		val ans_ix = scores.indexWhere (score => rank (score) <= 2)

		if (ans_ix == -1) {
			println ("IMPOSSIBLE")
		} else {
			val (x, y) = scores(ans_ix)
			println (x + ":" + y)
		}
	}

	val teams = scala.collection.mutable.Map.empty[String, (Int, Int, Int, Int, String)]
	val scores = (List.tabulate (30)(i => List.tabulate (30-i)(j => (i+j+1, j)))).flatten
	var enemy = ""

	def update(team: (Int, Int, Int, Int, String), score: (Int, Int)): (Int, Int, Int, Int, String) = {
		val (n, p, d, g, name) = team
		val (x, y) = score
		val pp = if (x > y) 3 else if (x < y) 0 else 1
		(n + 1, p + pp, d + x - y, g + x, name)
	}

	def read(scanner: Scanner): Unit = {
		val a, b = scanner.next ()
		val xy = scanner.next ()
		val x = xy(0) - '0'
		val y = xy(2) - '0'
		teams(a) = update(teams.getOrElse(a, (0, 0, 0, 0, a)), (x, y))
		teams(b) = update(teams.getOrElse(b, (0, 0, 0, 0, b)), (y, x))
	}

	def compare(a: (Int, Int, Int, Int, String), b: (Int, Int, Int, Int, String)): Int = {
		val (n_a, p_a, d_a, g_a, name_a) = a
		val (n_b, p_b, d_b, g_b, name_b) = b
		if (p_a > p_b) 1
		else if (p_a < p_b) -1
		else if (d_a > d_b) 1
		else if (d_a < d_b) -1
		else if (g_a > g_b) 1
		else if (g_a < g_b) -1
		else if (name_a < name_b) 1
		else if (name_a > name_b) -1
		else 0
	}

	def rank(score: (Int, Int)): Int = {
		val (x, y) = score
		def my_score(): (Int, Int, Int, Int, String) = {
			update(teams("BERLAND"), score)
		}
		def enemy_score(s: (Int, Int, Int, Int, String)): (Int, Int, Int, Int, String) = {
			val (n, p, d, g, name) = s
			if (name == enemy) update(s, (y, x)) else s
		}

		(teams.values.count (x => compare(my_score(), enemy_score(x)) < 0)) + 1
	}

}
