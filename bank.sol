// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0<0.9.0;
/**
   * @title Bank
   * @dev ContractDescription
   * @custom:dev-run-script Bank.sol
   */
contract Bank{
    mapping(address=>uint) public user_account;
    mapping (address=>bool) public user_exist;

    function createAcoount() public payable  returns(string memory){
        require(user_exist[msg.sender]==false,"Account already exits");
        user_account[msg.sender]=msg.value;
        user_exist[msg.sender]=true;
        return "Account Created";
    }
    function deposit(uint amount) public payable returns(string memory){
        require(user_exist[msg.sender]==true,"Account not found");
        require(amount>0,"Amoount should be greater than 0");
        user_account[msg.sender]+=amount;
        return "Amount added";
    } 
    function withdraw(uint amount) public payable returns(string memory){
        require(user_exist[msg.sender]==true,"Account not found");
        require(amount>0,"Amount should be greater than 0");
        require(user_account[msg.sender]>amount,"Balance is less than entered ammount");
        user_account[msg.sender]-=amount;
        return "Amount withdrawn";
    }
    function getbalance() public view returns(uint){
        return user_account[msg.sender];
    }
    function user_exists() public view returns(bool){
        return user_exist[msg.sender];
    }
}
