require "osl"

class NumEffectStateTest < Test::Unit::TestCase
  def setup
    @nstate  = Osl::State::NumEffectState.new
  end

  def test_new
    assert_not_nil(Osl::State::NumEffectState.new)
  end

  def test_super_class
    assert_true(@nstate.is_a?(Osl::State::SimpleState))
  end

  def test_show
    assert_true(@nstate.respond_to?(:show))
  end

  def test_generate
    moves = @nstate.generate
    assert_not_nil(moves)
    assert_true(moves.is_a?(Array))
    assert_true(moves.first.is_a?(Osl::Move))
  end

  def test_makeMove
    moves = @nstate.generate
    assert_nothing_raised do
      @nstate.makeMove(moves.first)
    end
    assert_nothing_raised do
      @nstate.make_move(moves.first)  # alias
    end
    assert_nothing_raised do
      @nstate.move(moves.first)  # alias
    end
  end

  def test_makeMove_from_csa
    assert_nothing_raised do
      @nstate.makeMove("+7776FU")
    end
  end

  def test_isValidMove
    moves = @nstate.generate
    assert_true(@nstate.isValidMove(moves.first))
    assert_false(@nstate.isValidMove(Osl::Move.new))
  end

  def test_valid?
    moves = @nstate.generate
    assert_true(@nstate.valid?(moves.first))
    assert_false(@nstate.valid?(Osl::Move.new))
  end

  def test_isValidMove_from_csa
    assert_true(@nstate.isValidMove("+7776FU"))
    assert_true(@nstate.valid?("+7776FU"))  # alias
    assert_false(@nstate.isValidMove("-7776FU"))
    assert_nil(@nstate.isValidMove(""))
    assert_nil(@nstate.isValidMove("7776FU"))
    assert_nil(@nstate.isValidMove("-7776"))
  end

  def test_inCheck
    assert_false(@nstate.inCheck)
    assert_false(@nstate.in_check?)  # alias
  end
end
