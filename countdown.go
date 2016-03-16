package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

var (
	formats = []string{
		"2006-01-02",
		"Monday",
		"2/1",
		"15:04",
		time.Kitchen,
		time.RFC1123,
		time.RFC1123Z,
		time.RFC3339,
		time.RFC3339Nano,
		time.RFC822,
		time.RFC822Z,
		time.RFC850,
	}
)

func main() {
	var target time.Time

	input := os.Args[1]

	d, err := time.ParseDuration(input)
	if err == nil {
		target = time.Now().Add(-d)
	}

	for _, format := range formats {
		t, err := time.Parse(format, input)
		if err == nil {
			target = t
			break
		}
	}

	if target.Unix() == new(time.Time).Unix() {
		fmt.Printf("Could not parse date: %q\n", input)
		os.Exit(1)
	}

	fmt.Println(target)

	// Assume year was not given and add the target to current time.
	if target.Year() == 0 {
		epoch := time.Now().Truncate(24 * time.Hour)
		diff := target.Sub(epoch)
		fmt.Println(diff)

		target = time.Now().Add(diff)
	}

	fmt.Println(target)

	for {
		diff := target.Sub(time.Now())
		days := int(diff.Hours() / 24)
		hours := int(diff.Hours()) % 24
		minutes := int(diff.Minutes()) % 60
		seconds := int(diff.Minutes()*60) % 60

		postfix := "left"
		scale := 1

		if target.Before(time.Now()) {
			postfix = "ago"
			scale = -1
		}

		var parts []string

		if diff.Hours() > 24 {
			parts = append(parts, fmt.Sprintf("%v days", scale*days))
		}

		if diff.Hours() > 0 {
			parts = append(parts, fmt.Sprintf("%v hours", scale*hours))
		}

		if diff.Minutes() > 0 {
			parts = append(parts, fmt.Sprintf("%v minutes", scale*minutes))
		}

		parts = append(parts, fmt.Sprintf("%v seconds", scale*seconds))
		parts = append(parts, postfix)

		fmt.Printf("\r%v", strings.Join(parts, " "))

		time.Sleep(1 * time.Second)
	}
}
