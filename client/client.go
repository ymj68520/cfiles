package main

import (
	"bufio"
	"crypto/rand"
	"encoding/json"
	"fmt"
	"log"
	"math/big"
	"os"
	"strings"
	"time"
)

func clientSendMessageAndListen() {
	go clientTcpListen()
	fmt.Printf("客户端开始监听，地址：%s\n", clientAddr)
	fmt.Println("--------------------------------")
	fmt.Println("|  已进入PBFT测试Demo客户端，请启动全部节点后再发送消息！ :)  |")
	fmt.Println(" ---------------------------------------------------------------------------------")
	fmt.Println("请在下方输入要存入节点的信息：")
	stdReader := bufio.NewReader(os.Stdin)
	for {
		data, err := stdReader.ReadString('\n')
		if err != nil {
			fmt.Println("Error reading from stdin")
			panic(err)
		}
		r := new(Request)
		r.Timestamp = time.Now().UnixNano()
		r.clientAddr = clientAddr
		r.Message.ID = getRandom()
		r.Message.Content = strings.TrimSpace(data)
		br, err := json.Marshal(r)
		if err != nil {
			log.Panic(err)
		}

		fmt.Println(string(br))
		content := jointMessage(cRequest, br)
		tcpDial(content, nodeTable["NO"])
	}
}

func getRandom() int {
	x := big.NewInt(10000000000)
	for {
		result, err := rand.Int(rand.Reader, x)
		if err != nil {
			log.Panic(err)
		}
		if result.Int64() > 1000000000 {
			return int(result.Int64())
		}
	}
}
