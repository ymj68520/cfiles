#!/bin/bash
# 图书馆管理系统
#
BOLD=$(tput smso)
NORMAL=$(tput rmso)
# 欢迎界面
greeting() {
    tput clear
    tput cup 5 15
    printf "${BOLD}Super Duper Unix Library"
    tput cup 12 10
    printf "${NORMAL}This is the Unix library application"
    tput cup 14 10
    printf "Please enter any key to continue..."
}

# 主菜单界面
mainmenu() {
    tput clear
    tput cup 5 10
    printf "Unix Library Main Menu"
    tput cup 7 20
    printf "0: ${BOLD}EXIT${NORMAL} this program"
    tput cup 9 20
    printf "1: ${BOLD}EDIT${NORMAL} menu"
    tput cup 11 20
    printf "2: ${BOLD}REPORTS${NORMAL} menu"

    tput cup 13 10
    printf "Enter your choice > "
    read CHOICE
    case "$CHOICE" in
        0) tput clear; exit 0;;
        1) editmenu;;
        2) REPORTS;;
        *) handle_error 20 10;;
    esac
}

# 错误处理
handle_error() {
    tput cup $1 $2
    printf "Wrong input, try again."
    tput cup $(($1+1)) $2
    printf "Press any key to continue..."
    read ANSWER
    tput clear
}

ADD(){
    answer=y
    while [ y = "$answer" ]
    do
        tput clear;
        tput cup 5 10; echo "UNIX Library - ${BOLD}ADDMORE"
        tput cup 7 23; echo "Title:"
        tput cup 9 22; echo "Author:"
        tput cup 11 20;echo "Category:"
        tput cup 12 20;echo "sys: system, ref: reference, tb: textbook"
        echo "${NORMAL}"
        tput cup 7 30; read title;
        tput cup 9 30; read author;
        tput cup 11 30;read category;
        status=in
        echo "$title:$author:$category:$status:$bname:$date" >> ULIB_FILE;
        tput cup 14 10;echo "Any more to add?(Y)yes or (N)no > ";
        read answer
        case $answer in
            [Y,y]) answer=y;;
                *) answer=n;;
        esac
    done
}
DISPLAY(){
    OLD_IFS="$IFS"
    answer=y;
    while [ "$answer" = y ]
    do
        tput clear; tput cup 3 5; echo "Enter the Title/Author >_ \b";
        read response;
        grep -i "$response" ULIB_FILE > TEMP;
        if [ -s TEMP ]
        then
            IFS=":";
            read title author category status bname date < TEMP;
            tput cup = 10
            echo "UNIX Library - ${BOLD}DISPLAYMORE${NORMAL}"
            tput cup 7 23; echo "Title:  $title"
            tput cup 8 22; echo "Author: $author"
            case $category in
                [T,t][B,b])   word=textbook;;
                [Ss][Yy][Ss]) word=system;;
                [Rr][Ee][Ff]) word=reference;;
                *)            word=undefined;;
            esac
            tput cup 9 20; echo "Category: $word"
            tput cup 12 24;echo "Status: $status"
            if [ "$status" = "out" ]; then
                tput cup 11 14; echo "Checked out by: $bname"
                tput cup 12 24; echo "Date: $date"
            fi
        else
            tput cup 7 10; echo "$response not found"
        fi;
        tput cup 15 10; echo -n "Any more to look?(y)Yes or (n)NO>_ "
        read answer
        case $answer in
            [Yy]*) answer=y;;
            *) answer=n;
        esac
    done
    IFS="$OLD_IFS"    
}

UPDATE(){
    OLD_IFS="$IFP"
    answer=y;
    while [ "$answer" = y ]; do
        new_status= ;new_bname= ;new_date= ;
        tput clear;tput cup 3 5; echo "Enter the Title/Author > "
        read response
        grep -i "$response" ULIB_FILE > TEMP
        if [ -s TEMP ]; then
            IFS=":"
            read title author category status bname date < TEMP;
            tput cup 5 10
            echo "UNIX Library-${BOLD}UPDATESTATUSMODE${NORMAL}"
            tput cup 7 23; echo "Title:  $title"
            tput cup 8 22; echo "Author: $author"
            case $category in
                [Tt][Bb])       word=textbook;;
                [Ss][Yy][Ss])   word=system;;
                [Rr][Ee][Ff])   word=reference;;
                *)              word=undefined;;
            esac
            tput cup 9 20; echo "Category: $word"
            tput cup 10 22;echo "Status: $status"
            if [ "${status}" = "in" ]; then
                new_status=out;
                tput cup 11 18; echo "New status: $new_status"
                tput cup 12 14; echo -n "Checked out by: "
                read new_bname;
                new_date='date'+%D;
                tput cup 13 24; echo "Date: $new_date"
            else
                new_status=in;
                tput cup 11 14; echo "Checked out by: $bname"
                tput cup 12 14; echo "Date: $date"
                tput cup 15 18: echo "New status: $new_status"
            fi
            grep -iv "$title:$author:$category:$status:$bname:$date" ULIB_FILE > TEMP
            mv TEMP ULIB_FILE
            echo "${title}:${author}:${category}:">>ULIB_FILE
        else
            tput cup 8 10; echo "$response not found"
        fi
        tput cup 16 10; echo "Any more to Update?(y)Yes or (n)NO > "
        read answer;
        case $answer in
             [Yy]*) answer=y;;
            *) answer=n;
        esac
    done
    IFS="$OLD_IFS"
    exit 0
}
DELETE(){
    OLD_IFS="$IFS"
    answer=y;
    while [ "$answer" = y ]; do
        tput clear; tput cup 3 5; echo -n "Enter the Title/Author"
        read response
        grep -i "$response" ULIB_FILE > TEMP
        if [ -s TEMP ]; then
            IFS=":"
            read title author category status bname date < TEMP;
            tput cup 5 10
            echo "UNIX Library-${BOLD}DELETEMORE${NORMAL}"
            tput cup 7 23; echo "Title: $title"
            tput cup 8 22; echo "Author: $author"
            case $category in
                [Tt][Bb])       word=textbook;;
                [Ss][Yy][Ss])   word=system;;
                [Rr][Ee][Ff])   word=reference;;
                *)              word=undefined;;
            esac
            tput cup 9 20; echo "Category: $word"
            tput cup 10 22;echo "Status: $status"
            if [ "$ststus" = "out" ]; then
                tput cup 11 14; echo "Checked out by: $bname"
                tput cup 12 24; echo "Date: $date"
            fi
            tput cup 9 20; echo "Delete this book?(y)Yes or (n)NO > "
            read answer
            if [ $answer = y -o $answer = Y ]; then
                grep -iv "$title:$author:$category:$status:$bname:$date" ULIB_FILE > TEMP
                mv TEMP ULIB_FILE
            fi
        else
            tput cup 7 10; echo "$response not found"
        fi
        tput cup 15 10; echo "Any more to delete?(y)Yes or (n)NO > "
        read answer
        case $answer in
             [Yy]*) answer=y;;
            *) answer=n;
        esac
    done
    IFS="$OLD_IFS"
    exit 0;


}

# edit菜单
editmenu() {
    while true; do
        # 显示edit菜单
        tput clear
        tput cup 5 10
        printf "${BOLD}UNIX Library${NORMAL} - Edit Menu"
        tput cup 9 20
        printf "0: ${BOLD}RETURN${NORMAL} to the main menu"
        tput cup 11 20
        printf "1: ${BOLD}ADD${NORMAL} a book"
        tput cup 13 20
        printf "2: ${BOLD}UPDATE${NORMAL} a book"
        tput cup 15 20
        printf "3: ${BOLD}DISPLAY${NORMAL} a book"
        tput cup 17 20
        printf "4: ${BOLD}DELETE${NORMAL} a book"

        # 分析用户输入
        tput cup 21 10
        printf "Enter your choice > "
        read CHOICE
        case "$CHOICE" in
            0) break;;  # 退出循环
	        1) ADD;;
	        2) UPDATE;;
	        3) DISPLAY;;
	        4) DELETE;;
            *) handle_error 20 10;;
        esac
    done
}


# 启动主函数
editmenu
