package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func abs(a, b int) int {
	r := a - b

	if r >= 0 {
		return r
	} else {
		return -r
	}
}

func solve(in *FastScanner, out *bufio.Writer) {
	n := in.NextInt()

	v := make([]int, n+1)
	marked := make([]int, n+1)

	for i := 1; i <= n; i++ {
		v[i] = in.NextInt()
	}

	//11 3 10 7 15 10 10 11 11 13 11 12 14 14 15
	// 1  2 3 4  5  6  7  8  9 10 11 12 13 14 15

	for i := 1; i <= n; i++ {
		source := v[i]
		for source != v[source] {
			if marked[source] != 0 {
				source = marked[source]
				break
			}

			dest := v[source]
			source = dest
		}
		marked[i] = source
		fmt.Printf("%d ", source)
	}

	fmt.Println()
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
