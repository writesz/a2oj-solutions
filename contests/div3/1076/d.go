package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
	"sort"
)

func solve(in *FastScanner, out *bufio.Writer) {
	testcases := in.NextInt()

	for t := 0; t < testcases; t++ {
		n := in.NextInt()

		a := make([]int, n+1)
		b := make([]int, n+1)

		for i := 1; i <= n; i++ {
			a[i] = in.NextInt()
		}

		for i := 1; i <= n; i++ {
			b[i] = in.NextInt()

			b[i] += b[i-1]
		}

		slices.SortFunc(a, func(q, w int) int {
			return w - q // reverse order
		})

		var max int64 = 0

		for i := 1; i <= n; i++ {
			if b[i] > n {
				break
			}

			var res int64 = int64(a[b[i]-1]) * int64(i)

			if res > max {
				max = res
			}
		}

		fmt.Println(max)
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
