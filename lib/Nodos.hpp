#ifndef COMPUESTOVISITANTE_HPP
#define COMPUESTOVISITANTE_HPP

/**
 *Nodos del patrón visitor
 */
class VisitorNode;
class Visitor;

/**
 * Nodos abstractos
 */
class Node;
class NodeList;
class VNodeList;
class LNodeList;
class INode;
class BinNode;
class LeafNode;

/**
 * Nodos concretos que heredan de INode
 */
class ForNode;
class WhileNode;
class IfNode;
class AssignNode;
class StmtListNode;
class SStmtListNode;
class ExprNode;
class ArgsNode;
class FuncNode;
class StmtNode;
class SStmtNode;

class LTNode;
class GTNode;
class EqNode;
class NEqNode;
class LTEqNode;
class GTEqNode;
class AndNode;
class OrNode;
class XorNode;
class NotNode;
class PotNode;


/**
 * Nodos concretos que heredan de BinNode
 */
class PlusNode;
class MinusNode;
class DiviNode;
class MultNode;

/**
 * Nodos concretos que heredan de LeafNode
 */
class IdentNode;
class IntNode;
class FloatNode;
class StrNode;
class BoolNode;




#endif
