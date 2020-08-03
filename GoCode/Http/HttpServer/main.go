package main

import (
	"net/http"
)

func HandConn(w http.ResponseWriter)

func main() {
	http.HandleFunc("/", HandConn)
}
