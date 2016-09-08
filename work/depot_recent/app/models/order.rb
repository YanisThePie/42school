class Order < ActiveRecord::Base
  PAYMENT_TYPES = ["Paypal", "Purchase order"]
end
