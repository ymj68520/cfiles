package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net"
)

func clientTcpListen() {
	addr, err := net.ResolveTCPAddr("tcp4", clientAddr)
	if err != nil {
		log.Panic(err)
	}
	listen, err := net.ListenTCP("tcp", addr)
	if err != nil {
		log.Panic(err)
	}
	defer listen.Close()

	for {
		conn, err := listen.Accept()
		if err != nil {
			log.Panic(err)
		}
		b, err := ioutil.ReadAll(conn)
		if err != nil {
			log.Panic(err)
		}
		fmt.Println(string(b))
	}
}

func (p *pbft) tcpListen() {
	listen, err := net.Listen("tcp", p.node.addr)
	if err != nil {
		log.Panic(err)
	}
	fmt.Printf("节点开启监听，地址：%s\n", p.node.addr)
	defer listen.Close()
	for {
		conn, err := listen.Accept()
		if err != nil {
			log.Panic(err)
		}
		b, err := ioutil.ReadAll(conn)
		if err != nil {
			log.Panic(err)
		}
		p.handleRequest(b)
	}

}

func tcpDial(context []byte, addr string) {
	addr1, err := net.ResolveTCPAddr("tcp4", clientAddr)
	if err != nil {
		log.Panic(err)
	}

	conn, err := net.DialTCP("tcp", nil, addr1)
	if err != nil {
		log.Println("connect error", err)
		return
	}

	_, err = conn.Write(context)
	if err != nil {
		log.Fatal(err)
	}
	conn.Close()
}
