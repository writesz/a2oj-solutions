package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *FastScanner, out *bufio.Writer) {
	testcases := in.NextInt()

	const MOD int64 = 1_000_000_007

	for t := 0; t < testcases; t++ {
		n := in.NextInt()

		left := make([]int, n+1)
		right := make([]int, n+1)

		for i := 1; i < n+1; i++ {
			li := in.NextInt()
			ri := in.NextInt()
			left[i] = li
			right[i] = ri
		}

		order := make([]int, 0, n)
		st := []int{1}

		for len(st) > 0 {
			v := st[len(st)-1]
			st = st[:len(st)-1]
			order = append(order, v)

			if left[v] != 0 {
				st = append(st, left[v])
				st = append(st, right[v])
			}
		}

		sum := make([]int64, n+1)
		ans := make([]int64, n+1)

		for i := len(order) - 1; i >= 0; i-- {
			v := order[i]
			if left[v] == 0 {
				sum[v] = 1
			} else {
				sum[v] = (sum[left[v]] + sum[right[v]] + 3) % MOD
			}
		}

		ans[1] = sum[1]
		st = []int{1}

		for len(st) > 0 {
			v := st[len(st)-1]
			st = st[:len(st)-1]

			if left[v] != 0 {
				a := left[v]
				b := right[v]

				ans[a] = (ans[v] + sum[a]) % MOD
				st = append(st, a)

				ans[b] = (ans[v] + sum[b]) % MOD
				st = append(st, b)
			}
		}

		for v := 1; v <= n; v++ {
			fmt.Printf("%v ", ans[v]%MOD)
		}

		fmt.Println()

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
