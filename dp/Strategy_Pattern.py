import string
import random
from typing import List
from abc import ABC, abstractmethod


class counter:
	def __init__(self):
		self.counter = 0

	def generate_id(self) -> int:
		self.counter += 1
		return self.counter

count = counter()

class SupportTicket:
	def __init__(self, customer, issue):
		self.customer = customer
		self.issue = issue
		self.id = count.generate_id()


class TicketOrderingStrategy(ABC):
	@abstractmethod
	def create_ordering(self, list: List[SupportTicket]) -> List[SupportTicket]:
		pass


class FIFOOrderingStrategy(TicketOrderingStrategy):
	def create_ordering(self, list:List[SupportTicket]) -> List[SupportTicket]:
		list_copy = list.copy()
		return list_copy


class FILOOrderingStrategy(TicketOrderingStrategy):
	def create_ordering(self, list:List[SupportTicket]) -> List[SupportTicket]:
		list_copy = list.copy()
		list_copy.reverse()
		return list_copy

class RandomOrderingStrategy(TicketOrderingStrategy):
	def create_ordering(self, list:List[SupportTicket]) -> List[SupportTicket]:
		list_copy = list.copy()
		random.shuffle(list_copy)
		return list_copy


class CustomerSupport:
	def __init__(self, strategy:TicketOrderingStrategy):
		self.tickets = []
		self.order_strategy = strategy

	def create_ticket(self, customer, issue) -> None:
		self.tickets.append(SupportTicket(customer, issue))


	def processTicket(self, ticket) -> None:
		print("-----------------------")
		print("id ", ticket.id)
		print("customer ", ticket.customer)
		print("issue ", ticket.issue)
		print("-----------------------\n\n")


	def process_tickets(self):
		""" Create the right ordering first before going to process the tickets """
		ticket_list = self.order_strategy.create_ordering(self.tickets)

		if len(ticket_list) == 0:
			Print("There are no tickets to process, Well Done!")
			return

		for ticket in ticket_list:
			self.processTicket(ticket)



if __name__ == "__main__":
	app = CustomerSupport(RandomOrderingStrategy())
	app.create_ticket("Sekhar", "staging 2 jenkin pipeline failing")
	app.create_ticket("Dinesh", "unable to find the good job")
	app.create_ticket("Sunkanna", "issue in getting support locally")
	app.create_ticket("Salaiah", "facing issue in understaing people")
	app.create_ticket("Eswar", "Fearing to get higher salary")
	app.create_ticket("Pedanna", "unable to drive bike")
	app.create_ticket("Shivann", "not able to forget drinking")

	app.process_tickets()
