package main

import (
	"fmt"
	"strconv"
	"os"
	"regexp"
	"strings"
	"github.com/jasonmoo/geo"
)

// Use the name of the command to figure out if we want to do a straight or a
// reverse lookup to the geocoding API. Anything with reverse in its name will
// be doing a reverse lookup.
func isReverseMode() bool {
	commandName := os.Args[0]
	reverseMatcher := regexp.MustCompile("reverse")
	return reverseMatcher.MatchString(commandName)
}

func parseCoordinates() (latitude, longitude float64, ok bool) {
	latitude, longitude, ok = 0, 0, false

	// Assuming seperated coordinates
	if len(os.Args) == 3 {
		lat, latOk := strconv.ParseFloat(os.Args[1], 64)
		long, longOk := strconv.ParseFloat(os.Args[2], 64)

		if nil != latOk || nil != longOk {
			return
		}

		latitude, longitude, ok = lat, long, true
	} else if len(os.Args) == 2 {
		latitude = 0
		longitude = 1
		ok = true
	}

	return
}

func ReverseGeocode(latitude, longitude float64) (*geo.Address, error) {
	coordinateString := fmt.Sprintf("%v,%v", latitude, longitude)
	return geo.ReverseGeocode(coordinateString)
}

func main() {
	var address *geo.Address
	var error error

	if isReverseMode() {
		latitude, longitude, ok := parseCoordinates()

		if ok != false {
			address, error = ReverseGeocode(latitude, longitude)
		}
	} else {
		query := strings.Join(os.Args[1:], " ")
		address, error = geo.Geocode(query)
	}

	if nil != error {
		fmt.Fprintln(os.Stderr, "Did not get any result")
		os.Exit(0)
	}

	fmt.Println(address)
}
