fun main() {
    var t = readLine()!!.toInt()
    repeat(t) {
        var n = readLine()!!.toInt()
        var ans = n
        var nc = n
        while (true) {
            if (n % 3 == 0 || n % 5 == 0) {
                ans = 0
                break
            } else if (n < 3) {
                ans = n
                break
            } else if (n < 5) {
                n -= 3
            } else {
                n -= 5
            }
        }
        n = nc
        while (true) {
            if (n % 3 == 0 || n % 5 == 0) {
                ans = 0
                break
            } else if (n < 3) {
                ans = minOf(ans, n)
                break
            } else {
                n -= 3
            }
        }
        println(ans)
    }
}
