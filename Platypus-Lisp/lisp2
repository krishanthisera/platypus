;; Each item may only have one go for an order. Pizza or Pasta or Pizza and Pasta. To add another Item to order Needs to create another order

;;Parent Class definition
(defclass order ()
((qty
		:initarg :qty
		:initform 0
		:accessor quantity)
(type
        :initarg :type 
        :accessor type
        :initform "None")
(amount
        :initarg :amount
        :reader amount
        :accessor val-amount
        :initform 0)
(generic-offer-type
        :initarg :offer-generic-type
        :initform "None"
        :accessor offer-generic-type)
(generic-offer-qty
        :initarg :offer-generic-qty
        :initform  0
        :accessor offer-generic-qty)
))

;;Child class pizza
(defclass pizza(order)(
(unit-price
        :initarg :unit-price
        :accessor unit-price
        :initform 12)
(discount-one
        :initarg :discount-one
        :accessor discount-one
        :initform 1)
(discount-two
        :initarg :discount-two
        :accessor discount-two
        :initform 0.91666667)
(discount-multi
        :initarg :discount-multi
        :accessor discount-multi
        :initform 0.83333333)
))

;;Child class pasta
(defclass pasta(order)(
(uni-price
        :initarg :unit-price
        :accessor unit-price
        :initform 8)
(discount-one
        :initarg :discount-one
        :accessor discount-one
        :initform 1)
(discount-two
        :initarg :discount-two
        :accessor discount-two
        :initform 0.9375)
(discount-multi
        :initarg :discount-multi
        :accessor discount-multi
        :initform 0.875)
))

(setf *accumulate-cost-session-wide* 0) ;; This cost is session wide and Not to be used in billing

;;Pizza and Pasta Amount Calculation
(defmethod calc-amount (order)
    (if(= *order-qty* 1)
        (setq disc (discount-one order)))
    (if(= *order-qty* 2)
        (setq disc (discount-two order)))
    (if(> *order-qty* 2)
        (setq disc (discount-multi order)))
	(setf (val-amount order) (* (* (unit-price order) disc) *order-qty*))
)

;;Order creation
(defun  make-order(*order-type* *order-qty*)
    ;;Make Pizza order
    (case *order-type*
    (1 (defparameter *pizza* (make-instance 'pizza :type "pizza" :qty *order-qty* :offer-generic-type "Garlic Bread" :offer-generic-qty (truncate (/ *order-qty* 3.0))))
    (calc-amount *pizza*) (setf *accumulate-cost-session-wide* (+ (val-amount *pizza*) *accumulate-cost-session-wide*))
     (if (= *is-pizza* 1) (princ "Previous Pizza order Has been Altered!!!!")) (setq *is-pizza* 1))

    ;;Make Pasta order
    (9 (defparameter *pasta* (make-instance 'pasta :type "pasta" :qty *order-qty* :offer-generic-type "Soft Drink" :offer-generic-qty  (truncate (/ *order-qty* 3.0))))
    (calc-amount *pasta*) (setf *accumulate-cost-session-wide* (+ (val-amount *pasta*) *accumulate-cost-session-wide*))
    (if (= *is-pasta* 1) (princ "Previous Pasta order Has been Altered"))(setq *is-pasta* 1)))
)

;;Variable Un-bounding
(defun unbound-all()
    (makunbound '*order-type*)
    (makunbound '*order-qty*)
    (makunbound '*order-id*)
    (makunbound '*accumulate-cost*)
    (makunbound '*pizza*)
    (makunbound '*pasta*)
    (makunbound '*is-pizza*)
    (makunbound '*is-pasta*)
)

;;Order Summary
(defun fin-order(*terminal-width*)

    ;;General Order Data
    (defvar *accumulate-cost* 0)
    (princ (make-string *terminal-width* :initial-element #\#))
    (terpri)
    (format t "Order ID: ~d~%" *order-id*)
    (princ (make-string *terminal-width* :initial-element #\#))
    (terpri)

    ;;Pizza Order
    (if(= *is-pizza* 1) (progn (princ (make-string *terminal-width* :initial-element #\>)) (terpri)
    (format t "Quantity of Pizza order: ~d~%" (quantity *pizza*))
    (format t "Total cost of Pizza order: ~d~%" (amount *pizza*))
    (setf *accumulate-cost* (+ *accumulate-cost* (amount *pizza*)))
    (format t "Eligible generic offers on Pizza order: ~d~%" (offer-generic-type *pizza*))
    (format t "Generic offers for this Pizza order : ~d~%" (offer-generic-qty *pizza*))
    (princ (make-string *terminal-width* :initial-element #\<))
    (terpri)))

    ;;Pasta Order
    (if(= *is-pasta* 1) (progn (princ (make-string *terminal-width* :initial-element #\>)) (terpri)
    (format t "Quantity of Pasta order: ~d~%" (quantity *pasta*))
    (format t "Total cost of Pasta order: ~d~%" (amount *pasta*))
    (setf *accumulate-cost* (+ *accumulate-cost* (amount *pasta*)))
    (format t "Eligible generic offers on Pasta order: ~d~%" (offer-generic-type *pasta*))
    (format t "Generic offers for this Pasta order : ~d~%" (offer-generic-qty *pasta*))
    (princ (make-string *terminal-width* :initial-element #\<))
    (terpri)))

    ;;Final Order
    (princ (make-string *terminal-width* :initial-element #\#))
    (terpri)
    (if(and (= *is-pizza* 1) (= *is-pasta* 1)) (progn(format t "Eligible special offer is Baklava!!!  This Order deserve : ~d~%"
    (truncate (min  (offer-generic-qty *pasta*) (offer-generic-qty *pizza*))))))
    (format t "Accumulated cost is ~d~%" *accumulate-cost*)
    (princ (make-string *terminal-width* :initial-element #\#))
    (terpri)

    ;;Un-bounding Flags and Variable
    (unbound-all)
)

;;Runner Definition for Looping order Creation
(defun runner()
    ;;Un-bounding the variables
    (makunbound '*order-type*)
    (makunbound '*order-qty*)
    ;;Initiating Pizza and Order Flags
    (defvar *is-pizza* 0)
    (defvar *is-pasta* 0)

    (print "Order Type Pizza [1] or Pasta [9] : ")
    (defvar *order-type* (parse-integer (read-line)))
    (print "Order Quantity : ")
    (defvar *order-qty* (read))
    (make-order *order-type* *order-qty*)
)

;;Maintain the HeartBeat of the System
(defun heart-beat() ;;System Controller
    ;;Inception
    (print "Order ID :" )
    (defvar *order-id* (read))
    (runner)

    ;;Keep adding items to the order
    (loop while (y-or-n-p "Add another Item?") ; Keep adding item to the order
        do (runner)
    )

    ;;Final bill
    (fin-order 60)
    ;;Un-bounding the order
    (makunbound '*order-id*)
)

;;Primary Loop to Keep the program alive
(loop while (y-or-n-p "Do you want to keep using the system up: ") ; Keep the program alive
        do (heart-beat)
)
;;Program END :)
(princ "Good Bye!!!")



