package main

import (
	"fmt"
	"net/http"
	"sync"
	"time"
)

var (
	mu      sync.Mutex
	wg      sync.WaitGroup
	printer Printer = &ConsolePrinter{}
)

func serve(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	defer mu.Unlock()
	w.Write([]byte("Hello World!\n"))
}

func main() {
	wg.Add(1)

	go func() {
		defer wg.Done()
		http.HandleFunc("/", serve)
		http.ListenAndServe(":8080", nil)
	}()

	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()

	for {
		select {
		case <-ticker.C:
			fmt.Println("Tick")
		default:
			for i := 0; i < 10; i++ {
				switch i % 3 {
				case 0:
					printer.Print("case 0")
				case 1:
					printer.Print("case 1")
				case 2:
					printer.Print("case 2")
				}
			}
			break
		}
	}

	wg.Wait()
}

type Printer interface {
	Print(string)
}

type ConsolePrinter struct {
}

func (p *ConsolePrinter) Print(s string) {
	fmt.Println(s)
}

