cmake_minimum_required(VERSION 3.21)
project(Lab_9_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_9_10 main.cpp Domain/Ticket.cpp Domain/Ticket.h Domain/Coin.h Domain/Coin.cpp Repository/Repository.h Repository/Repository.cpp Repository/Repo.cpp Repository/Repo.h Repository/RepoInFile.cpp Repository/RepoInFile.h Repository/RepoInMemory.cpp Repository/RepoInMemory.h Service.cpp Service.h CoinService.cpp CoinService.h Validator/CoinValidator.cpp Validator/CoinValidator.h Validator/TicketValidator.cpp Validator/TicketValidator.h UI.cpp UI.h Tests/TestDomain/TestCoinDomain.cpp Tests/TestDomain/TestCoinDomain.h Tests/TestDomain/TestTicketDomain.cpp Tests/TestDomain/TestTicketDomain.h Tests/TestAll/TestAll.cpp Tests/TestAll/TestAll.h Tests/TestRepository/TestTicketRepository.cpp Tests/TestRepository/TestTicketRepository.h Tests/TestRepository/TestTicketRepoInFile.cpp Tests/TestRepository/TestTicketRepoInFile.h)
