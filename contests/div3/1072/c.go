package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func dfs(x int, k int, g map[int]int) int {
	if x == k {
		return 0
	}
	if x < k || x == 0 {
		return -1
	}

	if v, ok := g[x]; ok {
		return v
	}

	a := x / 2
	b := (x + 1) / 2

	left := dfs(a, k, g)
	right := dfs(b, k, g)

	res := -1

	if left != -1 && right != -1 {
		if left < right {
			res = left + 1
		} else {
			res = right + 1
		}
	} else if left != -1 {
		res = left + 1
	} else if right != -1 {
		res = right + 1
	}

	g[x] = res

	return res
}

func countSteps(n int, k int, steps int) int {
	if n == 0 || n < k {
		return -1
	}

	if n == 1 {
		if k == 1 {
			return steps
		} else {
			return -1
		}
	}

	if n%2 == 0 {
		if n == k {
			return steps
		} else {
			return countSteps(n/2, k, steps+1)
		}
	} else {
		if n == k || n == k-1 {
			return steps
		} else {
			l := countSteps(n/2, k, steps+1)
			r := countSteps(n/2+1, k, steps+1)

			if r == -1 && l == -1 {
				return -1
			}

			if l > 0 && r > 0 {
				return min(l, r)
			}

			if l > 0 {
				return l
			} else {
				return r
			}
		}
	}
}

func solve(in *FastScanner, out *bufio.Writer) {
	testcases := in.NextInt()

	for t := 0; t < testcases; t++ {
		n := in.NextInt()
		k := in.NextInt()

		ans := -1

		if k > n {
			fmt.Println(ans)
			continue
		}
		g := make(map[int]int, 64)
		ans = dfs(n, k, g)

		fmt.Println(ans)
	}
}

// FastScanner: token-based scanner with low overhead.
type FastScanner struct {
	r *bufio.Reader
}

func NewFastScanner() *FastScanner {
	return &FastScanner{r: bufio.NewReaderSize(os.Stdin, 1<<20)}
}

func (fs *FastScanner) NextInt() int {
	sign, val := 1, 0
	c, err := fs.r.ReadByte()
	for (c < '0' || c > '9') && c != '-' {
		if err != nil {
			return 0
		}
		c, err = fs.r.ReadByte()
	}
	if c == '-' {
		sign = -1
		c, _ = fs.r.ReadByte()
	}
	for c >= '0' && c <= '9' {
		val = val*10 + int(c-'0')
		c, err = fs.r.ReadByte()
		if err != nil {
			break
		}
	}
	if err == nil {
		_ = fs.r.UnreadByte()
	}
	return sign * val
}

func (fs *FastScanner) NextInt64() int64 {
	sign, val := int64(1), int64(0)
	c, err := fs.r.ReadByte()
	for (c < '0' || c > '9') && c != '-' {
		if err != nil {
			return 0
		}
		c, err = fs.r.ReadByte()
	}
	if c == '-' {
		sign = -1
		c, _ = fs.r.ReadByte()
	}
	for c >= '0' && c <= '9' {
		val = val*10 + int64(c-'0')
		c, err = fs.r.ReadByte()
		if err != nil {
			break
		}
	}
	if err == nil {
		_ = fs.r.UnreadByte()
	}
	return sign * val
}

func (fs *FastScanner) NextString() string {
	c, err := fs.r.ReadByte()
	for c <= ' ' {
		if err != nil {
			return ""
		}
		c, err = fs.r.ReadByte()
	}
	buf := []byte{c}
	for {
		c, err = fs.r.ReadByte()
		if err != nil || c <= ' ' {
			break
		}
		buf = append(buf, c)
	}
	return string(buf)
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func GCD(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	if a < 0 {
		return -a
	}
	return a
}

func PowMod(base, exp, mod int64) int64 {
	base %= mod
	res := int64(1)
	for exp > 0 {
		if exp&1 == 1 {
			res = (res * base) % mod
		}
		base = (base * base) % mod
		exp >>= 1
	}
	return res
}

func LowerBound(a []int, x int) int {
	return sort.Search(len(a), func(i int) bool { return a[i] >= x })
}

func UpperBound(a []int, x int) int {
	return sort.Search(len(a), func(i int) bool { return a[i] > x })
}

func main() {
	in := NewFastScanner()
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	solve(in, out)
}
