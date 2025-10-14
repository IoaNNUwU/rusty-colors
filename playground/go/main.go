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

func exampleKeywords() {
	const (
		breakConst = "break"
		caseConst    = "case"
	 chanConst   = "chan"
		constConst  = "const"
		continueConst = "continue"
		defaultConst = "default"
		deferConst   = "defer"
		elseConst    = "else"
		fallthroughConst = "fallthrough"
		forConst     = "for"
		funcConst    = "func"
		goConst      = "go"
		gotoConst    = "goto"
		ifConst      = "if"
		importConst  = "import"
		interfaceConst = "interface"
		selectConst   = "select"
		switchConst   = "switch"
		typeConst    = "type"
		varConst      = "var"
	)

	fmt.Println(breakConst, caseConst, chanConst, constConst, continueConst,
		defaultConst, deferConst, elseConst, fallthroughConst, forConst,
		funcConst, goConst, gotoConst, ifConst, importConst, interfaceConst,
		selectConst, switchConst, typeConst, varConst)
}

func exampleKeywordsUsingKeywords() {
	breakLoop:
		for i := 0; i < 10; i++ {
			if i == 5 {
				break breakLoop
			}
		}
	caseSwitch:
		switch i := 0; i++; i < 10 {
		case 0:
			fmt.Println("case 0")
		case 1:
			fmt.Println("case 1")
		case 2:
			fmt.Println("case 2")
		default:
			fmt.Println("default")
		}
	chan chan int = make(chan int, 10)
	go func() {
		for i := 0; i < 10; i++ {
			chan <- i
		}
		close(chan)
	}()

	goto caseSwitch

	for i := range chan {
		fmt.Println(i)
	}

	const constVal = 10
	var varVal int = 10
	defer func() {
		fmt.Println("defer")
	}()
	continueLoop:
		for varVal < 20 {
			if varVal == 15 {
				continue continueLoop
			}
			varVal++
		}
	defaultSwitch:
		switch {
		default:
			fmt.Println("default")
		}
	deferExample:
		defer fmt.Println("defer example")
	fallthroughExample:
		switch {
		case 0:
			fallthrough
		default:
			fmt.Println("default")
		}
	forExample:
		for i := 0; i < 10; i++ {
			fmt.Println(i)
		}
	funcExample:
		func() {
			fmt.Println("func example")
		}()
	goExample:
		go fmt.Println("go example")
	ifExample:
		if varVal < 20 {
			fmt.Println("if example")
		}
	importExample:
		import "fmt"
	interfaceExample:
		type exampleInterface interface {
			Print()
		}
		var example exampleInterface = &exampleStruct{}
		example.Print()
	selectExample:
		select {
		case <-chan:
			fmt.Println("select example")
		}
	switchExample:
		switch varVal {
		case 10:
			fmt.Println("switch example")
		default:
			fmt.Println("default")
		}
	typeExample:
		type exampleStruct struct{}
	varExample:
		var exampleVar int
}
